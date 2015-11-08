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
  t_trame	data;

  data.crc = 42;
  data.size = 24;
  data.id = 0b1;
  strcpy(data.data, "Touche");
  boost::asio::io_service ios;
  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(host), port);
  boost::asio::ip::tcp::socket socket(ios);
  socket.connect(endpoint);
  boost::system::error_code error;
  socket.write_some(boost::asio::buffer(trame, sizeof(t_trame)), error);
  socket.read_some(boost::asio::buffer(trame, sizeof(t_trame)), error);
  socket.write_some(boost::asio::buffer(&data, sizeof(t_trame)), error);
  while (1);
  socket.close();
}

int main()
{
  t_trame	*trame = (t_trame*) malloc(sizeof(t_trame));

  trame->crc = 42;
  trame->size = 24;
  trame->id = 0x01;
  strcpy(trame->data, "WIN");
  send_something("127.0.0.1", 4242, trame);
  return 0;
}
