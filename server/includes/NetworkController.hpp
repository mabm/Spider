//
// Network.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:55:19 2015 Joris Bertomeu
// Last update Wed Oct 21 01:55:06 2015 Joris Bertomeu
//

#ifndef		_NETWORKCONTROLLER_HPP_
# define	_NETWORKCONTROLLER_HPP_
# include	<INetwork.hpp>
# include	<NetworkModel.hpp>
# include	<NetworkView.hpp>
# include	<stdexcept>
# include	<sstream>

class		NetworkController :	INetwork
{
private:
  NetworkModel	_networkModel;
  NetworkView	_networkView;

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
    } catch (const std::exception &e) {
      throw std::logic_error(e.what());
    }
  }
};

#endif
