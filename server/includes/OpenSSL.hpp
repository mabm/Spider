//
// OpenSSL.hpp for  in /home/jobertomeu/Work/Spider/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Oct 28 14:51:52 2015 Joris Bertomeu
// Last update Thu Oct 29 00:04:30 2015 Joris Bertomeu
//

#ifndef		_OPENSSL_HPP_
# define	_OPENSSL_HPP_
# include	<openssl/rsa.h>
# include	<openssl/pem.h>
# include	<openssl/err.h>
# include	<cstdlib>
# include	<string.h>

class		OpenSSL
{
private:
  RSA		*_pubKey;
  RSA		*_privKey;

private:
  void		generateRSA(const std::string &filenamePub,
			    const std::string &filenamePriv) {
    FILE * fpPub = fopen(filenamePub.c_str(), "rb");
    FILE * fpPriv = fopen(filenamePriv.c_str(), "rb");

    if (fpPub == NULL || fpPriv == NULL) {
      printf("Unable to open RSA Key\n");
      return NULL;
    }
    this->_pubKey = RSA_new();
    this->_privKey = RSA_new();
    this->_pubKey = PEM_read_RSA_PUBKEY(fpPub, &(this->_pubKey), NULL, NULL);
    this->_privKey = PEM_read_RSAPrivateKey(fpPriv, &(this->_privKey), NULL, NULL);
    fclose(fpPub);
    fclose(fpPriv);
  }

public:
  explicit	OpenSSL() {
    this->generateRSA(std::string("public.pem"), std::string("private.pem"));
  }
  virtual	~OpenSSL() {}
  void		printLastError(char *msg)
  {
    char * err = (char*) malloc(130);;
    ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err);
    printf("%s ERROR: %s\n",msg, err);
    free(err);
  }
  std::string	decrypt(unsigned char *str) {
    unsigned char	*decrypt = (unsigned char*) malloc(4096);
    int			ret;

    bzero(decrypt, 4096);
    ret = RSA_private_decrypt(256, (unsigned char*) str, (unsigned char*) decrypt, this->_privKey, RSA_PKCS1_PADDING);
    if (ret < 0)
      return (std::string(""));
    return (std::string((char*) decrypt));
  }
  unsigned char	*encrypt(const std::string &str) {
    unsigned char	*encrypt = (unsigned char*) malloc(4096);

    bzero(encrypt, 4096);
    RSA_public_encrypt(str.length(), (unsigned char*) str.c_str(), encrypt, this->_pubKey, RSA_PKCS1_PADDING);
    return (encrypt);
  }
};

#endif
