/*****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
#ifndef UTILS
#define UTILS

#include <string>
#include <openssl/rsa.h>
#include <XMLParser.h>

using namespace tinyxml2;

namespace utils{
	
	struct auth_var{
		char url[512];
		char verb[8];
		char access_key[128];
		char secret_key[128];
		char headers[128];
    char version[16];
		char path[128];
		char protocol[8];
		char host[128];
		int  port;
    bool is_secure;

    auth_var (): url(""), verb(""), access_key(""), secret_key(""), headers(""),
      path(""), protocol(""), host(""), port(80), is_secure(true)
    {
    }
		//copy constructor


	};

	struct http_var{
		char url[512];
		char verb[8];
		char version[16];
		char headers[128];
		
	};
	std::string get_protocol(const char* url);
	std::string get_host(const char* url);
	std::string hmac_sha256(std::string canonical_string ,const char *secret_key);
	std::string base64encode(const char * instring, size_t len);
	int base64decode(const char *decode, char *decoded, size_t len);
	RSA *import_ssh_key(std::string private_key_file, std::string passphrase= "");


void set_string_value(const XMLNode * element, const char* field, std::string& value);
void set_float_value(const XMLNode * element, const char* field, float& value);
void set_bool_value(const XMLNode * element, const char* field, bool& value);

}

#endif


