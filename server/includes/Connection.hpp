//
// Connection.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 02:29:24 2015 Joris Bertomeu
// Last update Wed Oct 21 12:23:20 2015 Joris Bertomeu
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
public:
  typedef	boost::shared_ptr<Connection>	ptr;
  static ptr	create(boost::asio::io_service &io_service) {
    return (ptr(new Connection(io_service)));
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
  explicit	Connection(boost::asio::io_service &io_service) : _socket(io_service) {
    this->_handshake = "Salut poupee\r\n";
  }
  void		handleWrite(const boost::system::error_code &e, size_t bytes_transferred) {
    if (!e)
      this->listenClient();
    else
      this->close();
  }
  void			handleRead(const boost::system::error_code &e, size_t bytes_transferred) {
    std::string		data;
    std::istream	is(&this->_buff);

    std::getline(is, data);
    std::cout << "From " << this->_socket.remote_endpoint().address().to_string() << " : " << data << std::endl;
    this->write("ok\r\n");
    if (!e)
      this->listenClient();
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
