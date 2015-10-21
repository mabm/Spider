#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	<boost/enable_shared_from_this.hpp>
#include	<iostream>
#include	<string>
#include	<sstream>

class						tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
private:
  boost::asio::deadline_timer			timer;
  boost::asio::ip::tcp::socket			m_socket;
  std::string					m_message;
  boost::array<char, 128>			m_buffer;

public:
  typedef boost::shared_ptr<tcp_connection>	pointer;

  static pointer				create(boost::asio::io_service& ios)
  {
    return pointer(new tcp_connection(ios));
  }

  boost::asio::ip::tcp::socket&			socket()
  {
    return m_socket;
  }
  void do_read() // (1)
  {
    // On lance une écoute
    boost::asio::async_read(m_socket, boost::asio::buffer(m_buffer), // (3)
			    boost::bind(&tcp_connection::handle_read, shared_from_this(),
					boost::asio::placeholders::error));
    timer.expires_from_now(boost::posix_time::seconds(5)); // (4)
    timer.async_wait(boost::bind(&tcp_connection::close, shared_from_this() )); //(5)
  }

  void start()
  {
    m_message = "Bienvenue sur le serveur!";

    boost::asio::async_write(m_socket, boost::asio::buffer(m_message),
			     boost::bind(&tcp_connection::handle_write, shared_from_this(),
					 boost::asio::placeholders::error)
			     );
  }

public:
  explicit					tcp_connection(boost::asio::io_service& io_service) :
    m_socket(io_service),
    timer(io_service, boost::posix_time::seconds(5)) // Commence à compter dès sa création
  {

  }

private:
    void handle_write(const boost::system::error_code& error)
    {
      if (!error)
	{
	  do_read(); // (2)
	}
      else {
	std::cout << error.message() << std::endl;
      }
    }

    void handle_read(const boost::system::error_code& error) // (6)
    {
      if (!error)
	{
	  // On réécoute
	  do_read();
	}
      else
	{
	  close();
	}
    }

    void close() // (7)
    {
      m_socket.close();
    }
};
