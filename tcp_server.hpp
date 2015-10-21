#include	"tcp_connection.hpp"

class tcp_server
{
public:
  tcp_server(boost::asio::io_service& io_service, int port) // (1)
    : m_acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
  {
    start_accept();
  }

private:
  void start_accept() // ATTENTION : ce code ne fonctionne pas, voir la suite... (6)
  {
    tcp_connection new_connection(m_acceptor.io_service()); // (2)

    m_acceptor.async_accept(new_connection.socket(), // (3)
			    boost::bind(&tcp_server::handle_accept, this, new_connection,
					boost::asio::placeholders::error));
  }

  void handle_accept(tcp_connection& new_connection, const boost::system::error_code& error) // (4)
  {
    if (!error)
      {
	std::cout << "Reçu un client!" << std::endl;
	new_connection.start();
	start_accept(); // (5)
      }
  }

  boost::asio::ip::tcp::acceptor m_acceptor;
};
