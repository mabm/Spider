//
// ICommand.hpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 14:31:38 2015 Jérémy Mediavilla
// Last update Mon Oct 26 17:31:59 2015 Jérémy Mediavilla
//

#ifndef				_ICOMMAND_HPP_
# define			_ICOMMAND_HPP_

# include			<string>

class				ICommand
{
protected:
  int				_id;
  std::string			_parameters;

private:
  virtual bool			execCommand(std::string) = 0;
  virtual void			setId(int) = 0;
  virtual void			setParameters(std::string) = 0;
};

#endif				// _ICOMMAND_HPP_
