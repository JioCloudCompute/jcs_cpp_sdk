#include <iostream>
#include <time.h>
#include "utils.cpp"
#include <string>
#include <string.h>
#include <map>
#include <curl/curl.h>

using namespace std;
using namespace utils;
namespace auth{
	class Authorization
	{	
		utils::auth_var data_;
	public:
		Authorization(const struct utils::auth_var data) : data_(data) //Use pass by const reference
		{	
			
			// test for this part:TODO
			if (strcmp(data.path,""))
				strcpy(data_.path,data.path);
			else strcpy(data_.path,"/");

			std::string protocol = utils::get_protocol(data_.url);	//utils
			std::string host = utils::get_host(data_.url);			//utils
			//todo: see how to handle
			if( protocol.compare("https") && protocol.compare("http"))
			{
				std::cout<<"Unsupported protocol present in given url";	
				//exit here
			}

			strcpy(data_.protocol,protocol.c_str());
			strcpy(data_.host, host.c_str());
			strcpy(data_.port,"None"); // default to http port
			
			int pos = host.find(":"); // if port specified in url

			if(pos != std::string::npos)
			{
				strcpy(data_.port,host.substr(pos+1).c_str());
				strcpy(data_.host, host.substr(0,pos).c_str());	
			}

		}

		void add_params(std::map <std::string,std::string > &params)
		{	
			//Add generic key-value pairs in the param map
			params["JCSAccessKeyId"] = data_.access_key;
			params["SignatureVersion"] = "2";
			params["SignatureMethod"] = "HmacSHA256";
			//Time Stamp
			time_t now = time(NULL);
			tm *gmtm = gmtime(&now);
			char stamp[64];
			//utf-8 encoding
			strftime(stamp,64,"%Y-%m-%dT%H:%M:%SZ",gmtm);
			params["Timestamp"] = stamp;
		}

		std::string _get_utf8_value(std::string value)
		{
			//todo(devender): To look at string to utf-8.
		}




		std::string sort_params(std::map<std::string ,std::string> &params)
		{
			
			std::string qs="";
			CURL *curl = curl_easy_init();
			char *value; 
			for (std::map<std::string,std::string>::iterator it=params.begin(); it!=params.end(); ++it)
			{
				//Some parse and safety check left  refer auth_handler.py
				// utf encoding on values left
				//url encoding
				value = curl_easy_escape(curl,it->second.c_str(),0);
				qs+=it->first+"="+value+"&";
			}
			qs[qs.length()-1]='\0'; //removing last &
			curl_free(value);
			return qs;


		}
		std::string string_to_sign(std::map <std::string , std::string> &params)
		{
			//Calculate the canonical string for the request
			std::string verb_ = data_.verb;
			std::string ss = verb_ + "\n" + data_.host;
			
			if(strcmp(data_.port,"None"))
			{
				ss += ":";
				ss+=data_.port;
			}

			ss= ss + "\n" + data_.path + "\n";
			add_params(params);
			ss+=sort_params(params);
			return ss;

		}

		void add_authorization(std::map<std::string, std::string> &params)
		{
		
			//data
			std::string canonical_string = string_to_sign(params);
			//HMAC SHA 256
			std::string hmac_256 = utils::hmac_sha256(canonical_string,data_.secret_key);
	    	//base64 and urlencode
			CURL *curl = curl_easy_init();
			char *hmac_Signature = curl_easy_escape(curl,utils::base64encode(&hmac_256[0], hmac_256.length()).c_str(),0);
			params["Signature"]=hmac_Signature;
		#ifdef CLI_DEBUG
			std::cout<<"HMAC SIGNATURE 0: " << utils::base64encode(&hmac_256[0], hmac_256.length())<<"\n";
			std::cout<<"HMAC SIGNATURE:  " << hmac_Signature<<"\n";
		#endif
			free(hmac_Signature);

		}
	};
}
