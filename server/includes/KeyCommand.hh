//
// KeyCommand.hh for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:17:43 2015 Jérémy Mediavilla
// Last update Wed Oct 28 10:53:04 2015 Joris Bertomeu
//

#ifndef				_KEYCOMMAND_HH_
# define			_KEYCOMMAND_HH_
# include			<ICommand.hpp>

class				KeyCommand : public ICommand
{
public:
  explicit			KeyCommand();
  virtual			~KeyCommand();
  bool				execCommand(const std::string &, const std::string &, const std::string &command);
  void				setId(const char &id);
  void				setParameters(const std::string &parameters);
};

#endif				// _KEYCOMMAND_HH_
