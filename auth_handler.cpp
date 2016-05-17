#include <iostream>
#include <time.h>
#include "utils.cpp"
#include <string>
#include <map>
#include <openssl/hmac.h>
#include <curl/curl.h>


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

	void add_params(std::map <std::string,std::string > &params)
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

	std::string _get_utf8_value(std::string value)
	{

	} 




	std::string sort_params(std::map<string ,string> &params){
		
		std::string qs="";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		{
			//Some parse and safety check left  refer auth_handler.py
			// utf encoding on values left
			qs+=it->first+"="+it->second+"&";
		}
		qs[qs.length()-1]="\0"; //removing last &
		return qs;


	}
	string string_to_sign(std::map <std::string , std::string) &params)
	{
		//Calculate the canonical string for the request
		std::string ss = data_.verb + "\n"+data_.host;
		
		if(strcmp(data_.port,"None"))
		{
			ss+=":" + data_.port;
		}

		ss+='\n' + data_.path + '\n';
		add_params(params);
		ss+=sort_params(params);
		return ss;

	}

	void add_authorization(std::map<string, string> &params)
	{
		//key
	
		//data
		std::string canonical_string = string_to_sign(params);
		char data[canonical_string.length()];
		strcpy(data,canonical_string);
		
		//hmac 
		unsigned char* hmac_256;
    	unsigned int len = 256;
    	
    	hmac_256 = (unsigned char*)malloc(sizeof(char) * len);
    	
    	HMAC_CTX ctx;
    	HMAC_CTX_init(&ctx);

		HMAC_Init_ex(&ctx, data.secret_key, strlen(data.secret_key), EVP_sha256(), NULL);
		HMAC_Update(&ctx,(unsigned char*)&data, strlen(data));
    	HMAC_Final(&ctx, hmac_256, &len);
    	HMAC_CTX_cleanup(&ctx);

    	//storing ascii result in hmac_256_
    	std::string hmac_256_ ="";
    	char temp[8];
    	for (int i = 0; i != len; i++)
        	{
        	sprintf(temp,"\\x%02x", (unsigned int)hmac_256[i]);
        	hmac_256_+=temp;
        	}
		free(hmac_256);

		//base64 encoding
		

		//urlencode
		CURL *curl = curl_easy_init();
		std::string hmac_Signature = curl_easy_escape(curl,,.length());
		

		params['Signature']=hmac_Signature;
	}






}