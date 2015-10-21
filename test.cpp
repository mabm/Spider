#include	"tcp_server.hpp"


int main()
{
  try
    {
      boost::asio::io_service	io_service;
      tcp_server		app(io_service);

      io_service.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
}
