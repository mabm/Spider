//
// ICommand.hpp for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 14:31:38 2015 Jérémy Mediavilla
// Last update Wed Oct 28 14:14:02 2015 Joris Bertomeu
//

#ifndef				_ICOMMAND_HPP_
# define			_ICOMMAND_HPP_

# include			<string>
# include			<iostream>

class				ICommand
{
protected:
  char				_id;
  std::string			_parameters;

public:
  virtual			~ICommand() {};
  char				getId() const { return (this->_id); };
  virtual bool			execCommand(const std::string &, const std::string &, const std::string&) = 0;
  virtual void			setId(const char&) = 0;
  virtual void			setParameters(const std::string&) = 0;
};

#endif				// _ICOMMAND_HPP_
