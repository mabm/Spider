//
// Server.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:34:45 2015 Joris Bertomeu
// Last update Tue Oct 27 22:04:09 2015 Joris Bertomeu
//
#ifndef		_SERVER_HPP_
# define	_SERVER_HPP_
# include	<stdexcept>
# include	<NetworkController.hpp>

class		Server
{
private:
  NetworkController		_networkController;

public:
  explicit	Server() {

  }
  virtual	~Server() {

  }
  void		init(int ac, char **argv) {
    if (ac != 2)
      throw std::logic_error("Usage : ./server <port>");
    try {
      this->_networkController.init(ac, argv);
    } catch (const std::exception &e) {
      throw std::logic_error(e.what());
    }
  }
  void		start() {

  }
};

#endif
