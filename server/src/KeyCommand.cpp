//
// KeyCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:23:34 2015 Jérémy Mediavilla
// Last update Wed Oct 28 03:29:46 2015 Joris Bertomeu
//

#include <KeyCommand.hh>

KeyCommand::KeyCommand()
{
  this->_id = 0b1;
}

KeyCommand::~KeyCommand()
{

}

bool		KeyCommand::execCommand(const std::string &command)
{
  (void)command;
  std::cout << "Key Command" << std::endl;

  return (true);
}

void		KeyCommand::setId(const char &id)
{
  this->_id = id;
}

void		KeyCommand::setParameters(const std::string &parameters)
{
  this->_parameters = parameters;
}
