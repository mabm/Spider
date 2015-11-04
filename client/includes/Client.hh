
#ifndef _CLIENT_HH_
# define _CLIENT_HH_

#include <iostream>
#include <ClientWindow.h>

class				Client
{
public:
	Client();
	~Client();

	bool			init(HINSTANCE instance);
	void			run();
	int				isRunning();

private:
	ClientWindow	_window;
	bool			_running;
};

#endif _CLIENT_HH_