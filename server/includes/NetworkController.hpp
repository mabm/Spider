//
// Network.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:55:19 2015 Joris Bertomeu
// Last update Wed Oct 21 05:24:05 2015 Joris Bertomeu
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
  boost::asio::ip::tcp::acceptor	*_acceptor;
  boost::asio::io_service		_io_service;

public:
  explicit	NetworkController() {

  }
  virtual	~NetworkController() {

  }
  int		checkPort(int ac, char **argv) const {
    int		i = 0;

    while (i < std::string(argv[1]).size()) {
      if (!(argv[1][i] >= '0' && argv[1][i] <= '9') && argv[1][i] != '-')
	throw std::logic_error("Invalid port number");
      i++;
    }
    std::istringstream(argv[1]) >> i;
    return (i);
  }
  void		init(int ac, char **argv) {
    try {
      std::stringstream	ss;

      ss << this->_networkModel.setPortNo(this->checkPort(ac, argv));
      this->_networkView.log(LOG_LVL_1, std::string("Port setted : " + ss.str()));
      this->_acceptor = new boost::asio::ip::tcp::acceptor(this->_io_service,
							   boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), std::atoi(ss.str().c_str())));
      this->accept();
      this->_io_service.run();
    } catch (const std::exception &e) {
      throw std::logic_error(e.what());
    }
  }
private:
  void		accept() {
    Connection::ptr	newConnection = Connection::create(this->_acceptor->get_io_service());

    this->_acceptor->async_accept(newConnection->socket(),
				  boost::bind(&NetworkController::handleAccept,
					      this, newConnection,
					      boost::asio::placeholders::error));
  }
  void		handleAccept(Connection::ptr newConnection, const boost::system::error_code &e) {
    if (!e) {
      newConnection->start();
      accept();
    }
  }
};

#endif
