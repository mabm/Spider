//
// main.cpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 00:30:40 2015 Joris Bertomeu
// Last update Wed Oct 21 01:24:12 2015 Joris Bertomeu
//

#include	<iostream>
#include	<Server.hpp>

int		main(int ac, char *argv[])
{
  Server	app;

  try {
    app.init(ac, argv);
    app.start();
  } catch (const std::exception &e) {
    std::cerr << "Exception catched : " << e.what() << std::endl;
    return (-1);
  }
  return (0);
}
