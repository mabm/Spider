//
// NetworkModel.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:59:38 2015 Joris Bertomeu
// Last update Wed Oct 21 01:49:18 2015 Joris Bertomeu
//

#ifndef		_NETWORKMODEL_HPP_
# define	_NETWORKMODEL_HPP_
# include	<stdexcept>

class		NetworkModel
{
private:
  int		_portNo;

public:
  explicit	NetworkModel() :
    _portNo(0) {}
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
};

#endif
