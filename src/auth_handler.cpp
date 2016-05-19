#include <iostream>
#include <time.h>
#include "utils.cpp"
#include <string>
#include <string.h>
#include <map>
#include <openssl/hmac.h>
#include <curl/curl.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
using namespace std;

class Authorization
{	
	auth_var data_;
public:
	Authorization(const struct auth_var data)
	{	

		strcpy(data_.url,data.url);
		strcpy(data_.verb , data.verb);
		strcpy(data_.access_key , data.access_key);
		strcpy(data_.secret_key, data.secret_key);
		strcpy(data_.headers,data.headers);
		// test for this part:TODO
		if (strcmp(data.path,""))
			strcpy(data_.path,data.path);
		else strcpy(data_.path,"/");

		std::string protocol = get_protocol(data_.url);	//utils
		std::string host = get_host(data_.url);			//utils

		if( protocol.compare("https") && protocol.compare("http"))
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
			strcpy(data_.host, host.substr(0,pos+1).c_str());	
		}

	}

	void add_params(std::map <std::string,std::string > &params)
	{	
		//Add generic key-value pairs in the param map
		params["JCSAccessKeyId"] = data_.access_key;
		params["SignatureVersion"] = "2";
		params["SignatureMethod"] = "HmacSHA256";
		//Time Stamp
		time_t now = time(0);
		tm *gmtm = gmtime(&now);
		char stamp[64];
		//utf-8 encoding
		strftime(stamp,64,"%Y-%m-%dT%H:%M:%SZ",gmtm);
		params["Timestamp"] = stamp;
	}

	std::string _get_utf8_value(std::string value)
	{

	} 




	std::string sort_params(std::map<std::string ,std::string> &params){
		
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
		char data[canonical_string.length()];
		strcpy(data,canonical_string.c_str());
			
		unsigned char* hmac_256;
    	unsigned int len = 256;
   		cout<<data<<endl;
    	hmac_256 = (unsigned char*)malloc(sizeof(char) * len);
    	
    	HMAC_CTX ctx;
    	HMAC_CTX_init(&ctx);

		HMAC_Init_ex(&ctx, data_.secret_key, strlen(data_.secret_key), EVP_sha256(), NULL);
		HMAC_Update(&ctx,(unsigned char*)&data, strlen(data));
    	HMAC_Final(&ctx, hmac_256, &len);
    	HMAC_CTX_cleanup(&ctx);
    	
    	//storing ascii result in hmac_256_
    	std::string hmac_256_ ="";
    	char temp[8];
    	for (int i = 0; i != len; i++)
        	{
        	sprintf(temp,"%03u", (unsigned int)hmac_256[i]);
        	hmac_256_+= atoi(temp);
        	}
		free(hmac_256);
		
		//base64 encoding
		//Length of hmac signature 256 bits(32bytes) : 64 base encoding length 4*32/3 Therfore introduced \0 at 44
		BIO *bio, *b64;
		char message[hmac_256_.length()];
		strcpy(message,hmac_256_.c_str());
		
		char message_out[46];
		b64 = BIO_new(BIO_f_base64());
		bio = BIO_new(BIO_s_mem());
		//bio = BIO_new_mem_buf(message_out, 100);
		BIO_push(b64, bio);
		BIO_write(b64, message, sizeof(message));
		BIO_flush(b64);
		BIO_read(bio, message_out,46);
		BIO_free_all(b64);
		message_out[44]='\0';
		
		//urlencode

		CURL *curl = curl_easy_init();
		std::string hmac_Signature = curl_easy_escape(curl,message_out,strlen(message_out));
		params["Signature"]=hmac_Signature;
	}
};