//
// CurrentWindowCommand.hh for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 15:21:10 2015 Jérémy Mediavilla
// Last update Mon Oct 26 16:50:44 2015 Jérémy Mediavilla
//

#ifndef				_CURRENTWINDOWCOMMAND_HH_
# define			_CURRENTWINDOWCOMMAND_HH_
# include			<ICommand.hpp>

class				CurrentWindowCommand : public ICommand
{
public:
  explicit			CurrentWindowCommand();
  virtual			~CurrentWindowCommand();
  bool				execCommand(std::string command);
  void				setId(int id);
  void				setParameters(std::string parameters);
};

#endif				// _CURRENTWINDOWCOMMAND_HH_
