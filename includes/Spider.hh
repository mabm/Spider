#ifndef			_SPIDER_HH_
# define		_SPIDER_HH_
# include		<iostream>
# include		<list>
# include		<Client.hh>

class			Spider
{
private:
  std::list<Client>	_clients;

public:
  explicit		Spider();
  virtual		~Spider();
};

#endif
