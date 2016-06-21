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
#ifndef REQUESTIFY
#define REQUESTIFY

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "auth_handler.hpp"
#include <fstream>
#include <curl/curl.h>
#include "config.hpp"
#include <utility>
#include <sstream>
using namespace std;
using namespace utils;
using namespace config;

namespace requestify
{
	size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up);
	pair<string, long> CURL_REQUEST(const string &request_string, ConfigHandler& config);
	pair<string, long> make_request(const utils::http_var &info, map<string, string> &params);
	
}
#endif