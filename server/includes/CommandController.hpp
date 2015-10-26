//
// CommandController.hpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 14:12:27 2015 Jérémy Mediavilla
// Last update Mon Oct 26 15:45:07 2015 Jérémy Mediavilla
//

#ifndef				_COMMANDCONTROLLER_HPP_
# define			_COMMANDCONTROLLER_HPP_
# include			<CommandModel.hpp>
# include			<CommandView.hpp>
# include			<ICommand.hpp>
# include			<string>

class				CommandController
{
private:
  CommandModel			_commandModel;
  CommandView			_commandView;
  std::map<char, ICommand*>	_commandList;


public:
  explicit			CommandController() {

  }
  /*  explicit			CommandController(openSSL &ssl) {

      }*/
  virtual			~CommandController() {

  }
  bool				parseCommand(const std::string command) {

  }

private:
  bool				verifyCRC(const std::string &) {

  }
  std::string			decryptCommand(const std::string &) {

  }
};

#endif				// _COMMANDCONTROLLER_HPP_
