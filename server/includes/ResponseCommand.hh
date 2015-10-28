//
// ResponseCommand.hh for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:22:47 2015 Jérémy Mediavilla
// Last update Wed Oct 28 10:53:29 2015 Joris Bertomeu
//

#ifndef				_RESPONSECOMMAND_HH_
# define			_RESPONSECOMMAND_HH_
# include			<ICommand.hpp>

class				ResponseCommand : public ICommand
{
public:
  explicit			ResponseCommand();
  virtual			~ResponseCommand();
  bool				execCommand(const std::string &, const std::string &, const std::string &command);
  void				setId(const char &id);
  void				setParameters(const std::string &parameters);
};

#endif				// _RESPONSECOMMAND_HH_
