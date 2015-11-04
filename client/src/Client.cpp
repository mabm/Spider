#include <Client.hh>

Client::Client() : _running(true), _assholeMode(true)
{
}

Client::~Client()
{
}

bool Client::init(HINSTANCE instance)
{
	if (!this->setProtection())
		return (false);
	if (!this->_window.init(instance))
	{
		OutputDebugString("Error Win Init\n");
		return (false);
	}
	return (true);
}

bool Client::setProtection()
{
	if (IsDebuggerPresent())
	{
		this->_assholeMode = true;
		return (false);
	}
	return (true);
}

void Client::run()
{
	// Add Thread Connexion
	while (this->isRunning())
	{
		//this->_running = false;
	}
}

void Client::runAssholeMode()
{
	return ;
	HWND	win;
	while (1)
	{
		win = GetForegroundWindow();
		ShowWindow(win, false);
	}
}

bool Client::isRunning()
{
	// Add Mutex Running
	if (this->_running)
		return (true);
	return (false);
}

bool Client::isAsshole()
{
	
	return (this->_assholeMode);
}
