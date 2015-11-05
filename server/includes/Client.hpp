//
// Connection.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 02:29:24 2015 Joris Bertomeu
// Last update Thu Oct 29 00:29:16 2015 Joris Bertomeu
//

#ifndef		_CLIENT_HPP_
# define	_CLIENT_HPP_
# include	<string>

class		Client
{
public:
  enum CLIENT_TYPE {
    UNDEF = -1,
    WIN,
    WEB
  };

private:
  CLIENT_TYPE	_type;
  int		_id;
  void		*_me;
  std::string	_version;

public:
  explicit	Client() {
    this->_type = Client::UNDEF;
    this->_id = -1;
    this->_me = NULL;
}
  virtual	~Client() {}
  void		setType(const Client::CLIENT_TYPE &type) {
    this->_type = type;
  }
  Client::CLIENT_TYPE	getType() const {
    return (this->_type);
  }
  void		setId(const int &id) {
    this->_id = id;
  }
  int		getId() const {
    return (this->_id);
  }
  void		setMe(void *me) {
    this->_me = me;
  }
  void		*getMe() const {
    return (this->_me);
  }
  void		setVersion(const std::string &version) {
    this->_version = version;
  }
  std::string	getVersion() const {
    return (this->_version);
  }
};

#endif
