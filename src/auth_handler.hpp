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
#ifndef AUTHHANDLER_H
#define AUTHHANDLER_H

#include "utils.hpp"
#include <string>
#include <string.h>
#include <map>

const std::string HMAC_SHA256_ALGORITHM = "HmacSHA256";
const std::string UTF8_CHARSET = "UTF-8";
const std::string JCS_ACCESS_KEY_ID = "JCSAccessKeyId";
const std::string SIGNATURE_VERSION = "SignatureVersion";
const std::string SIGNATURE_METHOD = "SignatureMethod";
const std::string TIMESTAMP = "Timestamp";
const std::string SIGNATURE = "Signature";

namespace auth{
	class Authorization
	{ 
	public:
		Authorization(const struct utils::auth_var& data); //Use pass by const reference
		void add_params(std::map <std::string,std::string > &params);
		std::string _get_utf8_value(const std::string& value);
		std::string sort_params(const std::map<std::string ,std::string> &params);
		std::string string_to_sign(std::map <std::string , std::string> &params);
		void add_authorization(std::map<std::string, std::string> &params);
	};
}

#endif
