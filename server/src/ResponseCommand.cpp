//
// ResponseCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 15:34:08 2015 Jérémy Mediavilla
// Last update Mon Oct 26 16:48:12 2015 Jérémy Mediavilla
//

#include <ResponseCommand.hh>

ResponseCommand::ResponseCommand()
{

}

ResponseCommand::~ResponseCommand()
{

}

bool		ResponseCommand::execCommand(std::string command)
{
  (void)command;
  return (true);
}

void		ResponseCommand::setId(int id)
{
  this->_id = id;
}

void		ResponseCommand::setParameters(std::string parameters)
{
  this->_parameters = parameters;
}