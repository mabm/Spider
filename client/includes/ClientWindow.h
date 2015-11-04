#ifndef _Client_Window_HH_
# define _Client_Window_HH_
#include	<Windows.h>

class				ClientWindow
{
public:
	ClientWindow();
	~ClientWindow();

	bool			init(HINSTANCE instance);

private:
	bool			_inited;
	HWND			_hwnd;
	WNDCLASSEX		_winClass;	
};

#endif /* _Client_Window_HH_ */