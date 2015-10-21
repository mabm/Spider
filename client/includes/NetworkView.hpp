//
// NetworkView.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 01:03:16 2015 Joris Bertomeu
// Last update Wed Oct 21 01:52:25 2015 Joris Bertomeu
//

#ifndef		_NETWORKVIEW_HPP_
# define	_NETWORKVIEW_HPP_
# define	LOG_LVL_1	1
# define	LOG_LVL_2	2
# define	LOG_LVL_3	3

# include	<iostream>

class		NetworkView
{
public:
  explicit	NetworkView() {}
  virtual	~NetworkView() {

  }
  void		log(int logLvl, std::string str) const {
    std::cout << str << std::endl;
  }
};

#endif
