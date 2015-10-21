//
// Connection.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 02:29:24 2015 Joris Bertomeu
// Last update Wed Oct 21 05:19:27 2015 Joris Bertomeu
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
  void		start() {
    boost::asio::async_write(this->_socket,
			     boost::asio::buffer(this->_handshake),
			     boost::bind(&Connection::handleWrite, shared_from_this(),
					 boost::asio::placeholders::error,
					 boost::asio::placeholders::bytes_transferred));
  }

private:
  explicit	Connection(boost::asio::io_service &io_service) : _socket(io_service) {
    this->_handshake = "Salut poupee\n";
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
    std::cout << "Say from Read : " << data << std::endl;
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
    //ADD TIMER
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
