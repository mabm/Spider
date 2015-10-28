//
// MouseCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:32:04 2015 Jérémy Mediavilla
// Last update Wed Oct 28 10:51:46 2015 Joris Bertomeu
//


#include <MouseCommand.hh>

MouseCommand::MouseCommand()
{
  this->_id = 0b11;
}

MouseCommand::~MouseCommand()
{

}

bool		MouseCommand::execCommand(const std::string &srvId, const std::string &clientId, const std::string &command)
{
  (void)command;
  return (true);
}

void		MouseCommand::setId(const char &id)
{
  this->_id = id;
}

void		MouseCommand::setParameters(const std::string &parameters)
{
  this->_parameters = parameters;
}
