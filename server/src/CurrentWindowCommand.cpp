//
// CurrentWindowCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 15:32:58 2015 Jérémy Mediavilla
// Last update Mon Oct 26 16:48:04 2015 Jérémy Mediavilla
//

#include <CurrentWindowCommand.hh>

CurrentWindowCommand::CurrentWindowCommand()
{

}

CurrentWindowCommand::~CurrentWindowCommand()
{

}

bool		CurrentWindowCommand::execCommand(std::string command)
{
  (void)command;
  return (true);
}

void		CurrentWindowCommand::setId(int id)
{
  this->_id = id;
}

void		CurrentWindowCommand::setParameters(std::string parameters)
{
  this->_parameters = parameters;
}