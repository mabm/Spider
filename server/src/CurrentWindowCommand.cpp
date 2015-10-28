//
// CurrentWindowCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:32:58 2015 Jérémy Mediavilla
// Last update Tue Oct 27 23:38:43 2015 Joris Bertomeu
//

#include <CurrentWindowCommand.hh>

CurrentWindowCommand::CurrentWindowCommand()
{
  this->_id = 0b10;
}

CurrentWindowCommand::~CurrentWindowCommand()
{

}

bool		CurrentWindowCommand::execCommand(const std::string &command)
{
  (void)command;
  return (true);
}

void		CurrentWindowCommand::setId(const char &id)
{
  this->_id = id;
}

void		CurrentWindowCommand::setParameters(const std::string &parameters)
{
  this->_parameters = parameters;
}
