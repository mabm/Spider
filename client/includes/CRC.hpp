//
// CRC.hpp for  in /home/mediav_j/mabm/Spider/server/includes
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Sat Nov  7 16:40:14 2015 Jérémy Mediavilla
// Last update Sat Nov  7 17:05:20 2015 Jérémy Mediavilla
//

#ifndef			_CRC_HPP_
# define		_CRC_HPP_

# include <string>

class			CRC
{
public:
	explicit		CRC() {}
	virtual		~CRC() {}
	static bool			verifyCRC(int crc, const std::string &str) {
		if (crc == CRC::calcCRC(str))
			return(true);
		return (false);
	}
	static int			calcCRC(const std::string &str) {
		int			sum = 0;
		int			i = 0;

		while (str.c_str()[i])
		{
			sum += str.c_str()[i];
			i++;
		}
		return (sum);
	}
};

#endif			// _CRC_HPP_