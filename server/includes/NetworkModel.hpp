//
// NetworkModel.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:59:38 2015 Joris Bertomeu
// Last update Tue Oct 27 22:08:49 2015 Joris Bertomeu
//

#ifndef		_NETWORKMODEL_HPP_
# define	_NETWORKMODEL_HPP_
# include	<stdexcept>
# include	<ICommand.hpp>
# include	<list>
# include	<Connection.hpp>

class		NetworkModel
{
private:
  int			_portNo;
  std::list<ICommand*>	_commandsList;
  std::list<Connection::ptr>	_clientList;
  int			_clientId;

public:
  explicit	NetworkModel() :
    _portNo(0), _clientId(0) {}
  virtual	~NetworkModel() {

  }
  int		setPortNo(int portNo) {
    if (portNo <= 0)
      throw std::logic_error("Port number must be > 0");
    this->_portNo = portNo;
    return (this->_portNo);
  }
  const int	&getPortNo() const {
    return (this->_portNo);
  }
  void		setCommandsList(const std::list<ICommand*> list) {
    this->_commandsList = list;
  }
  std::list<ICommand*>	&getCommandsList() {
    return (this->_commandsList);
  }
  void		addClient(Connection::ptr con) {
    this->_clientList.push_back(con);
  }
  Connection::ptr	getClientFromId(int id) {
    for (std::list<Connection::ptr>::iterator it = this->_clientList.begin();
	 it != this->_clientList.end();
	 ++it) {
      if ((*it)->getId() == id)
      	return (*it);
    }
    throw (std::logic_error("Client not found"));
  }
  int			getCurrentIdClient() {
    return (this->_clientId++);
  }
};

#endif
