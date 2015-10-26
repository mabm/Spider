//
// CommandModel.hpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Mon Oct 26 14:27:43 2015 Jérémy Mediavilla
// Last update Mon Oct 26 15:44:58 2015 Jérémy Mediavilla
//

#ifndef				_COMMANDMODEL_HPP_
# define			_COMMANDMODEL_HPP_

class				CommandModel
{
private:
  openSSL			&_openSSL;

public:
  explicit			CommandModel() {

  }
  virtual			~CommandModel() {

  }

private:
  openSSL			&getOpenSSL() const {
    return (this->_openSSL);
  }
};

#endif				// _COMMANDMODEL_HPP_
