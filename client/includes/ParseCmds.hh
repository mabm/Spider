#ifndef _PARSE_CMDS_HH
# define _PARSE_CMDS_HH
# define WIN32_LEAN_AND_MEAN 
# include <iostream>
# include <map>
# include <Windows.h>
# include <Connect.hh>
# include <PowrProf.h>

class ParseCmds
{
public:
	ParseCmds();
	~ParseCmds();

	typedef void (ParseCmds::*FuncCmd)(const char* data);
		
	void		execute(const t_trame & trame);
	void		sendSignal(const char* data);
	void		popMsg(const char* data);

private:
	std::map<char, FuncCmd> _cmds;
};

#endif /* _PARSE_CMDS_HH */