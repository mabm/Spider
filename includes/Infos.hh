#ifndef				_INFOS_HH_
# define			_INFOS_HH_
# include			<iostream>
# include			<string>
# include			<list>

class				Infos
{
private:
  std::string			_username;
  int				_time;
  std::string			_plateform;
  std::string			_password;
  std::list<std::string>	_users;
  std::string			_antiVirus;

public:
  explicit			Infos();
  virtual			~Infos();
};

#endif
