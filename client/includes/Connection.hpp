//
// Connection.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 02:29:24 2015 Joris Bertomeu
// Last update Wed Oct 28 23:35:56 2015 Joris Bertomeu
//

#ifndef		_CONNECTION_HPP_
# define	_CONNECTION_HPP_

# include	<IConnection.hpp>
# include	<string>

/* BOOST ASIO */

# include	<boost/bind.hpp>
# include	<boost/shared_ptr.hpp>
# include	<boost/enable_shared_from_this.hpp>
# include	<boost/asio.hpp>

/* BOOST ASIO */

class		Connection : public IConnection, public boost::enable_shared_from_this<Connection>
{
private:
    typedef struct	s_trame {
    char		id;
    int			size;
    int			crc;
    char		data[255];
  }			t_trame;

public:
  typedef	boost::shared_ptr<Connection>	ptr;
  static ptr	create(boost::asio::io_service &io_service) {
    return (ptr(new Connection(io_service)));
  };
  boost::asio::ip::tcp::socket&	socket() {
    return this->_socket;
  }
  void		write(char * trame, int size) {
    boost::asio::async_write(this->_socket,
    			     boost::asio::buffer(trame, size),
    			     boost::bind(&Connection::handleWrite, shared_from_this(),
    					 boost::asio::placeholders::error,
    			        	 boost::asio::placeholders::bytes_transferred));
  }
  void		read() {
    boost::asio::async_read_until(this->_socket,
				  this->_buff,
				  "\r\n",
				  boost::bind(&Connection::handleRead, shared_from_this(),
					      boost::asio::placeholders::error,
					      boost::asio::placeholders::bytes_transferred));
  }

private:
  explicit	Connection(boost::asio::io_service &io_service) : _socket(io_service) {
    this->_handshake = "Salut poupee\n";
  }
  void		handleWrite(const boost::system::error_code &e, size_t bytes_transferred) {
    if (!e)
      this->read();
    else
      this->close();
  }
  void			handleRead(const boost::system::error_code &e, size_t bytes_transferred) {
    std::string		response("c\r\n");
    std::string		data;
    std::istream	is(&this->_buff);
    t_trame		trame;
    char		tmp[sizeof(t_trame)];

    std::getline(is, data);
    std::cout << "From " << this->_socket.remote_endpoint().address().to_string() << " : " << data << std::endl;
    trame.id = 0b1;
    trame.crc = 42;
    trame.size = 24;
    memset(trame.data, 0, 255);
    strcpy(trame.data, "Bonjour les amis");
    std::cout << "Size : " << sizeof(t_trame) << std::endl;
    memcpy(&tmp, &trame, sizeof(t_trame));
    this->write(tmp, sizeof(t_trame));
    if (!e)
      this->read();
    else
      this->close();
  }
  void		listenClient() {
    boost::asio::async_read_until(this->_socket,
				  this->_buff,
				  "\r\n",
				  boost::bind(&Connection::handleRead, shared_from_this(),
					      boost::asio::placeholders::error,
					      boost::asio::placeholders::bytes_transferred));
  }
  void		close() {
    this->_socket.close();
  }

private:
  boost::asio::streambuf	_buff;
  boost::asio::ip::tcp::socket	_socket;
  std::string			_handshake;
};

#endif
