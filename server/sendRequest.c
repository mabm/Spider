#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

typedef struct	s_trame {
  char		id;
  int		size;
  int		crc;
  char		data[255];
}		t_trame;

void send_something(std::string host, int port, t_trame *trame)
{
  t_trame	init;
  t_trame      	buff;

  init.crc = 42;
  init.size = 24;
  init.id = 0x01;
  strcpy(init.data, "WEB");
  boost::asio::io_service ios;
  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(host), port);
  boost::asio::ip::tcp::socket socket(ios);
  socket.connect(endpoint);
  boost::system::error_code error;
  socket.write_some(boost::asio::buffer(&init, sizeof(t_trame)), error);
  socket.read_some(boost::asio::buffer(&buff, sizeof(t_trame)), error);
  socket.write_some(boost::asio::buffer(trame, sizeof(t_trame)), error);
  socket.close();
}

int main()
{
  t_trame	*trame = (t_trame*) malloc(sizeof(t_trame));
  char		*vars = getenv("QUERY_STRING");

  std::cout << "Content-type: text/html" << std::endl << std::endl;
  if (!vars)
    std::cout << "Bad parameters !" << std::endl;
  if (sscanf(vars, "crc=%d&size=%d&id=%d&data=%s", &(trame->crc), &(trame->size),
	     &(trame->id), &(trame->data)) != 4) {
    std::cout << "Bad parameters !" << std::endl;
    return (-1);
  }
  printf("-> data : %s\n", trame->data);
  // trame->crc = 42;
  // trame->size = 24;
  // trame->id = 0x01;
  send_something("127.0.0.1", 4242, trame);
  return 0;
}
