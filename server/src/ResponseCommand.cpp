//
// ResponseCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:34:08 2015 Jérémy Mediavilla
// Last update Thu Oct 29 00:39:51 2015 Joris Bertomeu
//

#include <ResponseCommand.hh>

ResponseCommand::ResponseCommand()
{
  this->_id = 0b100;
}

ResponseCommand::~ResponseCommand()
{

}

bool		ResponseCommand::execCommand(const std::string &srvId, const std::string &clientId, const std::string &command)
{
  (void)command;
  (void) srvId;
  (void) clientId;
  return (true);
}

void		ResponseCommand::setId(const char &id)
{
  this->_id = id;
}

void		ResponseCommand::setParameters(const std::string &parameters)
{
  this->_parameters = parameters;
}
