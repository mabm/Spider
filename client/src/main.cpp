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
#include		<Client.hh>

int	WINAPI		WinMain(HINSTANCE thisInstance, HINSTANCE prevInstance, LPSTR cmdLine, int nCmdShow)
{
  /* ClientController	app;

  try {
    app.init(ac, argv);
    app.start();
  } catch (const std::exception &e) {
    std::cerr << "Exception catched : " << e.what() << std::endl;
  } */
	Client	client;
	if (!client.init(thisInstance))
		return (EXIT_FAILURE);
	client.run();
	return (EXIT_SUCCESS);
}
