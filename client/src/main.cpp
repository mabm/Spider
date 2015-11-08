//
// main.cpp for  in /home/jobertomeu/Work/Spider/client
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 21 06:37:27 2015 Joris Bertomeu
// Last update Wed Oct 21 07:01:05 2015 Joris Bertomeu
//

#include		<Client.hh>

int	WINAPI		WinMain(HINSTANCE thisInstance, HINSTANCE prevInstance, LPSTR cmdLine, int nCmdShow)
{
	int			ac;
	LPWSTR		*args = CommandLineToArgvW(GetCommandLineW(), &ac);
	Client	client;
	if (!client.init(thisInstance, ac, args))
	{
		if (client.isAsshole())
			client.runAssholeMode();
		return (EXIT_FAILURE);
	}
	client.run();
	return (EXIT_SUCCESS);
}
