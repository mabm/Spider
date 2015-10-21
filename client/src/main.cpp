//
// main.cpp for  in /home/jobertomeu/Work/Spider/client
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 06:37:27 2015 Joris Bertomeu
// Last update Wed Oct 21 07:01:05 2015 Joris Bertomeu
//

#include		<ClientController.hpp>

int			main(int ac, char *argv[])
{
  ClientController	app;

  try {
    app.init(ac, argv);
    app.start();
  } catch (const std::exception &e) {
    std::cerr << "Exception catched : " << e.what() << std::endl;
  }
  return (0);
}
