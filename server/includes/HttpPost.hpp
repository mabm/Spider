//
// HttpPost.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Oct 27 11:19:04 2015 Joris Bertomeu
// Last update Sat Nov  7 17:14:26 2015 Joris Bertomeu
//

#ifndef		_HTTPPOST_HPP_
# define	_HTTPPOST_HPP_

# include	<string>
# include	<curl/curl.h>

class		HttpPost
{
  static size_t	writeData(void *ptr, size_t size, size_t nmemb, FILE *stream)
  {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
  }

public:
  static bool	request(const std::string &filePath, const std::string &url) {
    CURL	*curl;
    FILE	*fp;
    CURLcode	res;

    curl = curl_easy_init();
    printf("Calling %s\n", url.c_str());
    if (curl) {
      fp = fopen(filePath.c_str(), "wb");
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
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
};

#endif
