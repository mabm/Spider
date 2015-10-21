//
// Client.hpp for  in /home/jobertomeu/Work/Spider/client
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 06:38:39 2015 Joris Bertomeu
// Last update Wed Oct 21 07:04:57 2015 Joris Bertomeu
//

#ifndef		_CLIENTCONTROLLER_HPP_
# define	_CLIENTCONTROLLER_HPP_

# include	<stdexcept>
# include	<iostream>

# include	<ClientModel.hpp>
# include	<ClientView.hpp>

class		ClientController
{
private:
  ClientModel	_clientModel;
  ClientView	_clientView;

public:
  explicit	ClientController() {

  }
  virtual	~ClientController() {

  }
  void		init(int ac, char **argv) {
    if (ac != 3)
      throw std::logic_error("Usage : ./client_spider <ip_srv> <port>");
  }
  void		start() {

  }
};

#endif
