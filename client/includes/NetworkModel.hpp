//
// NetworkModel.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:59:38 2015 Joris Bertomeu
// Last update Wed Oct 21 10:48:26 2015 Joris Bertomeu
//

#ifndef		_NETWORKMODEL_HPP_
# define	_NETWORKMODEL_HPP_
# include	<stdexcept>
# include	<string>

class		NetworkModel
{
private:
  int		_portNo;
  std::string	_srvAddr;

public:
  explicit	NetworkModel() :
    _portNo(0),
    _srvAddr("") {}
  virtual	~NetworkModel() {

  }
  int		setSrvPort(int portNo) {
    if (portNo <= 0)
      throw std::logic_error("Port number must be > 0");
    this->_portNo = portNo;
    return (this->_portNo);
  }
  const int	&getSrvPort() const {
    return (this->_portNo);
  }
  void		setSrvAddr(const std::string &addr) {
    this->_srvAddr = addr;
  }
  const std::string	&getSrvAddr() const {
    return (this->_srvAddr);
  }
};

#endif
