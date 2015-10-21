//
// Network.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:55:19 2015 Joris Bertomeu
// Last update Wed Oct 21 11:00:39 2015 Joris Bertomeu
//

#ifndef		_NETWORKCONTROLLER_HPP_
# define	_NETWORKCONTROLLER_HPP_
# include	<Connection.hpp>
# include	<NetworkModel.hpp>
# include	<NetworkView.hpp>
# include	<stdexcept>
# include	<sstream>

class		NetworkController
{
private:
  NetworkModel	_networkModel;
  NetworkView	_networkView;
  boost::asio::io_service		_io_service;

public:
  explicit	NetworkController() {

  }
  virtual	~NetworkController() {

  }
  int		checkPort(int ac, char **argv) const {
    int		i = 0;

    while (i < std::string(argv[2]).size()) {
      if (!(argv[2][i] >= '0' && argv[2][i] <= '9') && argv[2][i] != '-')
	throw std::logic_error("Invalid port number");
      i++;
    }
    std::istringstream(argv[2]) >> i;
    return (i);
  }
  void		init(int ac, char **argv) {
    try {
      std::stringstream	ss;

      ss << this->_networkModel.setSrvPort(this->checkPort(ac, argv));
      this->_networkModel.setSrvAddr(std::string(argv[1]));
      this->_networkView.log(LOG_LVL_1, std::string("Port setted : " + ss.str()));

      this->connect();
      this->_io_service.run();
    } catch (const std::exception &e) {
      throw std::logic_error(e.what());
    }
  }
private:
  void					connect() {
    Connection::ptr			newConnection = Connection::create(this->_io_service);
    boost::asio::ip::tcp::socket	&socket = newConnection->socket();

    socket.async_connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(this->_networkModel.getSrvAddr()),
							this->_networkModel.getSrvPort()),
			 boost::bind(&NetworkController::handleConnect, this, newConnection,
				     boost::asio::placeholders::error));
    std::cout << "On passe ici" << std::endl;
  }
  void		handleConnect(Connection::ptr newConnection, const boost::system::error_code &e) {
    if (!e) {
      newConnection->read();
    }
  }
};

#endif
