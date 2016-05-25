#ifndef UTILS
#define UTILS

#include <string>
#include <map>
#include <string.h>
#include <iostream>
#include <openssl/hmac.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

namespace utils{
	
	struct auth_var{
		char url[512];
		char verb[8];
		char access_key[128];
		char secret_key[128];
		char headers[128];
		char path[128];
		char protocol[8];
		char host[128];
		char port[8];
		//copy constructor


	};

	struct http_var{
		char url[512];
		char verb[8];
		char version[16];
		char headers[128];
		
	};

	struct block_device_mapping{
		std::string device_name;
		bool delete_on_termination;
		int volume_size;
	};

	std::string get_protocol(char url[512])
	{	
		//EXTRA CHECK REQUIRED Regexp
		std::string url_ = url;
		return url_.substr(0,5);   //https
	}

	std::string get_host(char url[128])
	{
		std::string host_ = url;
		return host_.substr(8);
	}
	std::string hmac_sha256(std::string canonical_string ,const char *secret_key)
	{
		unsigned char* hmac_256;
	    unsigned int len = 32;
	   	hmac_256 = (unsigned char*)malloc(sizeof(char) * len);
	    
	    HMAC_CTX ctx;
	    HMAC_CTX_init(&ctx);
		HMAC_Init_ex(&ctx, secret_key, strlen(secret_key), EVP_sha256(), NULL);
		HMAC_Update(&ctx,(unsigned char*)(canonical_string.c_str()), strlen(canonical_string.c_str()));
		HMAC_Final(&ctx, hmac_256, &len);
	   	HMAC_CTX_cleanup(&ctx);
	   	hmac_256[len]='\0';
	   	return (char *)hmac_256;
	}

	std::string base64encode(std::string ascii_message)
	{	
		//Length of hmac signature 256 bits(32bytes) : 64 base encoding length 4*32/3 Therfore introduced \0 at 44		
		BIO *bio, *b64;
		char message[ascii_message.length()];
		strcpy(message,ascii_message.c_str());
		
		const int mlen = 46;	
		char b64message[mlen];
		b64 = BIO_new(BIO_f_base64());
		bio = BIO_new(BIO_s_mem());
		BIO_push(b64, bio);
		BIO_write(b64, message, sizeof(message));
		BIO_flush(b64);
		int len = BIO_read(bio, b64message,mlen);
		BIO_free_all(b64);
		//use len to remove \n
		b64message[len-1]='\0';
		return b64message;

	}
}

#endif


