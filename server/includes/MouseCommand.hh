//
// MouseCommand.hh for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:22:08 2015 Jérémy Mediavilla
// Last update Tue Oct 27 23:31:13 2015 Joris Bertomeu
//

#ifndef				_MOUSECOMMAND_HH_
# define			_MOUSECOMMAND_HH_
# include			<ICommand.hpp>

class				MouseCommand : public ICommand
{
public:
  explicit			MouseCommand();
  virtual			~MouseCommand();
  bool				execCommand(const std::string &command);
  void				setId(const char &id);
  void				setParameters(const std::string &parameters);
};

#endif				// _MOUSECOMMAND_HH_
