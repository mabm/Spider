//
// MouseCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 15:32:04 2015 Jérémy Mediavilla
// Last update Mon Oct 26 17:32:28 2015 Jérémy Mediavilla
//


#include <MouseCommand.hh>

MouseCommand::MouseCommand()
{

}

MouseCommand::~MouseCommand()
{

}

bool		MouseCommand::execCommand(std::string command)
{
  (void)command;
  return (true);
}

void		MouseCommand::setId(int id)
{
  this->_id = id;
}

void		MouseCommand::setParameters(std::string parameters)
{
  this->_parameters = parameters;
}
