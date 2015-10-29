//
// Connection.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 02:29:24 2015 Joris Bertomeu
// Last update Thu Oct 29 00:05:34 2015 Joris Bertomeu
//

#ifndef		_CONNECTION_HPP_
# define	_CONNECTION_HPP_

# include	<IConnection.hpp>
# include	<string>
# include	<list>
# include	<ICommand.hpp>
# include	<OpenSSL.hpp>

/* BOOST ASIO */

# include	<boost/bind.hpp>
# include	<boost/shared_ptr.hpp>
# include	<boost/enable_shared_from_this.hpp>
# include	<boost/asio.hpp>

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

public:
  typedef	boost::shared_ptr<Connection>	ptr;
  static ptr	create(std::list<ICommand*> &commandsList, boost::asio::io_service &io_service) {
    return (ptr(new Connection(commandsList, io_service)));
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
    this->write(this->_handshake);
  }

private:
  explicit	Connection(std::list <ICommand*> &commandsList, boost::asio::io_service &io_service) : _socket(io_service), _commandsList(commandsList) {
    this->_handshake = "Salut poupee\r\n";
  }
  void		handleWrite(const boost::system::error_code &e, size_t bytes_transferred) {
    if (!e)
      this->listenClient();
    else
      this->close();
  }
  void			handleRead(const boost::system::error_code &e, size_t bytes_transferred) {
    if (e) {
      std::cout << "Error !!!!!!" << std::endl;
      return;
    }
    this->execCommand(this->_socket.remote_endpoint().address().to_string(), bytes_transferred);
    this->write("ok\r\n");
  }
  void		listenClient() {
    boost::asio::async_read(this->_socket,
			    this->_buff,
			    boost::asio::transfer_exactly(268),
			    boost::bind(&Connection::handleRead, shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
  }
  void		close() {
    this->_socket.close();
  }
  void		execCommand(const std::string &from, size_t bytes_transferred) {
    bool	find = false;
    t_trame	trame;

    if (bytes_transferred != sizeof(t_trame)) {
      std::cout << "Invalid trame " << bytes_transferred << " bytes" << std::endl;
      return;
    }

    memcpy(&trame, boost::asio::buffer_cast<const void *>(this->_buff.data()), sizeof(t_trame));
    for (std::list<ICommand*>::iterator it = this->_commandsList.begin();
	 it != this->_commandsList.end() && !find; ++it) {
      if ((*it)->getId() == trame.id) {
	std::cout << "Command found with size about " << trame.size << " and checkSum about " << trame.crc << std::endl;
	(*it)->execCommand(this->_socket.local_endpoint().address().to_string(), from, std::string(trame.data));
	find = true;
      }
    }
    std::cout << "Decrypted : " << this->_openSSL.decrypt(this->_openSSL.encrypt(trame.data)) << std::endl;
    if (!find)
      std::cout << "Command not found" << std::endl;
  }

private:
  boost::asio::streambuf	_buff;
  boost::asio::ip::tcp::socket	_socket;
  std::string			_handshake;
};

#endif
