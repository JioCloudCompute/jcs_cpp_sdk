#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "auth_handler.cpp"
#include <fstream>
#include <curl/curl.h>
#include "config.cpp"
#include <utility>
using namespace std;
using namespace utils;
using namespace config;

namespace requestify{
	string response;
	size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
	{ //callback must have this declaration
	    //buf is a pointer to the data that curl has for us
	    //size*nmemb is the size of the buffer
	    for (int c = 0; c<size*nmemb; c++)
	    {
	        response.push_back(buf[c]);
	    }
	    return size*nmemb; //tell curl how many bytes we handled
	}

	pair<string, long> CURL_REQUEST(const string &request_string, ConfigHandler& config)
	{
		CURL* curl; // curl object

		curl_global_init(CURL_GLOBAL_ALL);
		curl = curl_easy_init();

		//headers
		struct curl_slist *header_list = NULL;
		header_list = curl_slist_append(header_list, "Content-Type: application/json");
		curl_slist_append(header_list, "Accept-Encoding: identity");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);
		
		//SSL verifiation off
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, config.check_secure());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, config.check_secure());
		
		curl_easy_setopt(curl, CURLOPT_URL, request_string.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
		// curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
		CURLcode curl_code = curl_easy_perform(curl);
		long http_code = 0;
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
		curl_easy_cleanup(curl);
		curl_global_cleanup();

		return make_pair(response, http_code);
		
	}


	pair<string, long> make_request(const utils::http_var &info, map<string, string> &params , string data ="")
	{
		utils::auth_var auth_data;
		response.clear();
		//Access Key ,Secret Key, Debug Mode, Secure Mode Config
		config::ConfigHandler config;

		strcpy(auth_data.url, info.url);
		strcpy(auth_data.verb, info.verb);
		strcpy(auth_data.headers, info.headers);
		strcpy(auth_data.access_key, config.get_access_key().c_str());
		strcpy(auth_data.secret_key, config.get_secret_key().c_str());

		//Set the Path according to your need
		string path = "";
		strcpy(auth_data.path,path.c_str());   //

		// Removing '/' from url
		if(info.url[strlen(info.url)-1] == '/')
			auth_data.url[strlen(auth_data.url)-1] == '\0';

		//Sending the url info to authorization to generate signature. 
		auth::Authorization object(auth_data);
		object.add_authorization(params);

		string request_string = info.url; 
		request_string+="/?";

		for (map<string, string>::iterator it = params.begin() ; it != params.end() ; ++it)
		{
			request_string+=it->first+"="+it->second+"&";
		}
		request_string[request_string.length()-1]='\0'; //removing last &

		// TODO: Header handling remaining
		cout<<request_string<<endl;

		return CURL_REQUEST(request_string, config);
		
		
	}
}