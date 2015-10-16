#ifndef		_CLIENT_HH_
# define	_CLIENT_HH_
# include	<string>
# include	<Infos.hh>

class		Client
{
public:
  enum		STATE
    {
      ONLINE,
      OFFLINE,
      SUSPEND
    };

private:
  std::string	_ipAddr;
  STATE		_state;
  std::string	_id;
  Infos		_infos;

public:
  explicit	Client();
  virtual	~Client();
};

#endif
