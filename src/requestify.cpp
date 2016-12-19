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
#include "requestify.hpp"
#include <vector>
#include "auth_handler.hpp"
#include <fstream>
#include <curl/curl.h>
#include <sstream>
#include <iostream>

using namespace std;
using namespace utils;

namespace requestify
{
	//string response ;
	size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
	{   
      string & response = *(string *)up;
      response.append(buf, size*nmemb/sizeof(char));
	    return size*nmemb; //tell curl how many bytes we handled
	} 

	pair<string, long> CURL_REQUEST(const string &request_string, const utils::auth_var& info)
	{
		CURL* curl; // curl object
		CURLcode res;
		curl_global_init(CURL_GLOBAL_ALL);
		curl = curl_easy_init();
		//headers
		struct curl_slist *header_list = NULL;
		header_list = curl_slist_append(header_list, "Content-Type: application/json");
		curl_slist_append(header_list, "Accept-Encoding: identity");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);
		
		//SSL verifiation off
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, info.is_secure);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, info.is_secure);
		
		curl_easy_setopt(curl, CURLOPT_URL, request_string.c_str());
    string response;
    string header;
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header); 
		// curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
		res = curl_easy_perform(curl);

		// Connection was not successful or timed out
		if(res!=0)
		{
			curl_easy_cleanup(curl);
			curl_global_cleanup();
			return make_pair("", 1);
		}

		long http_code = 0;
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
		curl_easy_cleanup(curl);
		//curl_global_cleanup();

		return make_pair(response, http_code);
	}

	pair<string, long> make_request(const utils::auth_var& info, map<string, string>& params)
	{

		//Sending the url info to authorization to generate signature. 
		auth::Authorization object(info);
		object.add_authorization(params);

		string request_string = info.url; 
		stringstream ss;
		ss<<request_string<<"/?";


		for (map<string, string>::iterator it = params.begin() ; it != params.end() ; ++it)
		{
			ss<<it->first<<"="<<it->second<<"&";
		}
		request_string = ss.str();
		request_string[request_string.length()-1]='\0'; //removing last &

		#ifdef CLI_DEBUG
				// TODO: Header handling remaining
				cout<<request_string<<endl;
		#endif
		return CURL_REQUEST(request_string, info);
	}

}
