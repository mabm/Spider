//
// HttpPost.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Oct 27 11:19:04 2015 Joris Bertomeu
// Last update Sun Nov  8 04:08:39 2015 Joris Bertomeu
//

#ifndef		_HTTPPOST_HPP_
# define	_HTTPPOST_HPP_

# include	<string>
# include	<curl/curl.h>
# include	<cstdlib>
# include	<string.h>

class		HttpPost
{
  static size_t	writeData(void *ptr, size_t size, size_t nmemb, FILE *stream)
  {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
  }

  /* Converts a hex character to its integer value */
  static char from_hex(char ch) {
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
  }

  /* Converts an integer value to its hex character*/
  static char to_hex(char code) {
    static char hex[] = "0123456789abcdef";
    return hex[code & 15];
  }

public:
  static bool	request(const std::string &filePath, const std::string &url) {
    CURL	*curl;
    FILE	*fp;
    CURLcode	res;

    curl = curl_easy_init();
    printf("Calling %s\n", (char*) url.c_str());
    if (curl) {
      fp = fopen(filePath.c_str(), "wb");
      curl_easy_setopt(curl, CURLOPT_URL, (char*) url.c_str());
      curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
      res = curl_easy_perform(curl);
      (void) res;
      curl_easy_cleanup(curl);
      fclose(fp);
      return (true);
    }
    return (false);
  }
  static char *url_encode(char *str) {
    char *pstr = str, *buf = (char*) malloc(strlen(str) * 3 + 1), *pbuf = buf;
    while (*pstr) {
      if (isalnum(*pstr) || *pstr == '-' || *pstr == '_' || *pstr == '.' || *pstr == '~')
	*pbuf++ = *pstr;
      else if (*pstr == ' ')
	*pbuf++ = '+';
      else
	*pbuf++ = '%', *pbuf++ = to_hex(*pstr >> 4), *pbuf++ = to_hex(*pstr & 15);
      pstr++;
    }
    *pbuf = '\0';
    return buf;
  }
  /* Returns a url-decoded version of str */
  /* IMPORTANT: be sure to free() the returned string after use */
  static char *url_decode(char *str) {
    char *pstr = str, *buf = (char*) malloc(strlen(str) + 1), *pbuf = buf;
    while (*pstr) {
      if (*pstr == '%') {
	if (pstr[1] && pstr[2]) {
	  *pbuf++ = from_hex(pstr[1]) << 4 | from_hex(pstr[2]);
	  pstr += 2;
	}
      } else if (*pstr == '+') {
	*pbuf++ = ' ';
      } else {
	*pbuf++ = *pstr;
      }
      pstr++;
    }
    *pbuf = '\0';
    return buf;
  }

};

#endif
