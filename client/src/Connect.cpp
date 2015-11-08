#include <Connect.hh>

Connect::Connect() : _connected(false)
{
}

Connect::~Connect()
{
}

bool Connect::init(int ac, LPWSTR *av)
{
	this->_host = "10.16.252.196";
	this->_port = 4242;
	return (true);
}

bool Connect::isConnected()
{
	if (this->_connected == false)
		return (false);
	if (this->_error == boost::asio::error::eof)
		this->_connected = false;
	return (this->_connected);
}

bool Connect::start()
{
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(this->_host), this->_port);
	this->_socket = new boost::asio::ip::tcp::socket(this->_ios);
	try {
		this->_socket->connect(endpoint);
	}
	catch (const std::exception & e) {
		this->_connected = false;
		return (false);
	}
	this->send(0x01,"WIN");
	this->_connected = true;
	return (true);
}

bool Connect::send(const char & id, const std::string & data)
{
	this->_trame.crc = CRC::calcCRC(data);
	this->_trame.size = data.size();
	this->_trame.id = id;
	strcpy(this->_trame.data, data.c_str());
	this->_socket->write_some(boost::asio::buffer(&this->_trame, sizeof(t_trame)), this->_error);
	return (true);
}

t_trame Connect::read()
{
	this->_socket->read_some(boost::asio::buffer(&this->_trame, sizeof(t_trame)), this->_error);
	return (this->_trame);
}


