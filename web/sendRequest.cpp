//
// test.cpp for  in /var/www/spider
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Nov  7 15:07:05 2015 Joris Bertomeu
// Last update Sun Nov  8 03:37:30 2015 Joris Bertomeu
//

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
  int		start = time(NULL), end = 0;

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
  socket.read_some(boost::asio::buffer(&buff, sizeof(t_trame)), error);
  end = time(NULL) - start;
  std::cout << "{\"result\":\"" << buff.data << "\",\"status\":\"Executed\",\"time_spent\":" << end << "}" << std::endl;
  socket.close();
}

int main()
{
  t_trame	*trame = (t_trame*) malloc(sizeof(t_trame));
  char		*vars = getenv("QUERY_STRING");

  std::cout << "Content-type: application/json" << std::endl << std::endl;
  if (!vars)
    std::cout << "Bad parameters !" << std::endl;
  if (sscanf(vars, "crc=%d&size=%d&id=%d&data=%s", &(trame->crc), &(trame->size),
	     &(trame->id), &(trame->data)) != 4) {
    std::cout << "Bad parameters !" << std::endl;
    return (-1);
  }
  send_something("127.0.0.1", 4242, trame);
  return 0;
}
