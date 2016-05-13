#include <iostream>
#include <time.h>
#include "utils.cpp"
#include <string>
#include <map>
class Authorization
{	
	auth_var data_;
public:
	Authorization(struct auth_var data)
	{
		data_.url = data.url;
		data_.verb = data.verb;
		data_.access_key = data.access_key;
		data_.secret_key = data.secret_key;
		data_.headers = data.headers;
		data_.path = data.path;

		std::string protocol = get_protocol(url);	//utils
		std::string host = get_host(url);			//utils

		if(!protocol.compare("https") || !protocol.compare("http"))
		{
			std::cout<<"Unsupported protocol present in given url";	
		}

		strcpy(data_.protocol,protocol.c_str());
		strcpy(data_.host, host.c_str());
		strcpy(data_.port,"None"); // default to http port
		
		int pos = host.find(":"); // if port specified in url
		if(pos != std::string::npos)
		{
			strcpy(data_.port,host.substr(pos+1).c_str());
			strcpy(data_.host, host.substr(0,pos+1);	
		}

	}

	void add_params(map <std::string,std::string > &params)
	{	
		//Add generic key-value pairs in the param map
		params['JCSAccessKeyId'] = data_.access_key;
		params['SignatureVersion'] = '2';
		params['SignatureMethod'] = 'HmacSHA256';
		//Time Stamp
		time_t now = time(0);
		tm *gmtm = gmtime(&now);
		char stamp[64];
		strftime(stamp,64,"%Y-%m-%dT%H:%M:%SZ",gmtm);
		params['Timestamp'] = stamp;
	}


}