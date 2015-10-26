//
// KeyCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 15:23:34 2015 Jérémy Mediavilla
// Last update Mon Oct 26 16:48:17 2015 Jérémy Mediavilla
//

#include <KeyCommand.hh>

KeyCommand::KeyCommand()
{

}

KeyCommand::~KeyCommand()
{

}

bool		KeyCommand::execCommand(std::string command)
{
  (void)command;
  return (true);
}

void		KeyCommand::setId(int id)
{
  this->_id = id;
}

void		KeyCommand::setParameters(std::string parameters)
{
  this->_parameters = parameters;
}
