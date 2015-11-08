#ifndef _CONNECT_HH_
# define _CONNECT_HH_
# define WIN32_LEAN_AND_MEAN 
# include <boost/asio.hpp>
# include <boost/array.hpp>
# include <iostream>
# include <atlstr.h>
# include <Windows.h>
# include <CRC.hpp>

typedef struct	s_trame {
	char		id;
	int			size;
	int			crc;
	char		data[255];
}				t_trame;

class			Connect
{
public:
	Connect();
	~Connect();

	bool							init(int ac, LPWSTR *av);
	bool							isConnected();
	bool							start();
	bool							send(const char & id, const std::string & data);
	t_trame							read();

private:
	bool							_connected;
	std::string						_host;
	int								_port;
	t_trame							_trame;
	boost::asio::io_service			_ios;
	boost::asio::ip::tcp::socket*	_socket;
	boost::system::error_code		_error;
};

#endif /* _CONNECT_HH_ */