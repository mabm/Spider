//
// CurrentWindowCommand.hh for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:21:10 2015 Jérémy Mediavilla
// Last update Tue Oct 27 23:31:50 2015 Joris Bertomeu
//

#ifndef				_CURRENTWINDOWCOMMAND_HH_
# define			_CURRENTWINDOWCOMMAND_HH_
# include			<ICommand.hpp>

class				CurrentWindowCommand : public ICommand
{
public:
  explicit			CurrentWindowCommand();
  virtual			~CurrentWindowCommand();
  virtual bool			execCommand(const std::string &command);
  virtual void			setId(const char &id);
  virtual void			setParameters(const std::string &parameters);
};

#endif				// _CURRENTWINDOWCOMMAND_HH_
