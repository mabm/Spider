#include <Client.hh>

Client::Client() : _running(true)
{
}

Client::~Client()
{
}

bool Client::init(HINSTANCE instance)
{
	if (!this->_window.init(instance))
	{
		OutputDebugString("Error Win Init\n");
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

int Client::isRunning()
{
	// Add Mutex Running
	if (this->_running)
		return (1);
	return (0);
}
