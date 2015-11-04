//
// CurrentWindowCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:32:58 2015 Jérémy Mediavilla
// Last update Thu Oct 29 00:40:35 2015 Joris Bertomeu
//

#include <CurrentWindowCommand.hh>

CurrentWindowCommand::CurrentWindowCommand()
{
  this->_id = 0b10;
}

CurrentWindowCommand::~CurrentWindowCommand()
{

}

bool		CurrentWindowCommand::execCommand(const std::string &srvId, const std::string &clientId, const std::string &command)
{
  (void) command;
  (void) srvId;
  (void) clientId;
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
