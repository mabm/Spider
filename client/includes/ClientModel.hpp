//
// ClientModel.hpp for  in /home/jobertomeu/Work/Spider/client
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 07:02:30 2015 Joris Bertomeu
// Last update Wed Oct 21 07:11:44 2015 Joris Bertomeu
//

#ifndef		_CLIENTMODEL_HPP_
# define	_CLIENTMODEL_HPP_

# include	<NetworkController.hpp>

class		ClientModel
{
private:
  NetworkController	_networkController;

public:
  explicit	ClientModel() {

  }
  virtual	~ClientModel() {

  }
  NetworkController	&getNetworkController() {
    return (this->_networkController);
  }
};

#endif
