//
// ResponseCommand.hh for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 15:22:47 2015 Jérémy Mediavilla
// Last update Mon Oct 26 16:47:20 2015 Jérémy Mediavilla
//

#ifndef				_RESPONSECOMMAND_HH_
# define			_RESPONSECOMMAND_HH_
# include			<ICommand.hpp>

class				ResponseCommand : public ICommand
{
public:
  explicit			ResponseCommand();
  virtual			~ResponseCommand();
  bool				execCommand(std::string command);
  void				setId(int id);
  void				setParameters(std::string parameters);
};

#endif				// _RESPONSECOMMAND_HH_
