#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "auth_handler.cpp"
#include <fstream>
#include <curl/curl.h>
#include "config.cpp"

using namespace std;

string response; //will hold the url's contents

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer
	cout<<"inside writeCallback"<<endl;
    for (int c = 0; c<size*nmemb; c++)
    {
        response.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}


string make_request(http_var &info, map<string, string> &params, string path = "", string data ="")
{
	string access_key, secret_key;
	auth_var auth_data;
	// reading keys from file
	ifstream infile("config.txt");
	string line;
	getline(infile,line);
	access_key = line;
	getline(infile,line);
	secret_key = line;
	infile.close();

	// Removing '/' from url
	if(info.url[strlen(info.url)-1] == '/')
		info.url[strlen(info.url)-1] == '\0';

	strcpy(auth_data.url, info.url);
	strcpy(auth_data.verb, info.verb);
	strcpy(auth_data.headers, info.headers);
	strcpy(auth_data.access_key, access_key.c_str());
	strcpy(auth_data.secret_key, secret_key.c_str());
	strcpy(auth_data.path,"/");
	Authorization obj(auth_data);
	obj.add_authorization(params);

	string request_string = info.url; 
	request_string+="/?";

	for (map<string, string>::iterator it = params.begin() ; it != params.end() ; ++it)
	{
		request_string+=it->first+"="+it->second+"&";
	}
	request_string[request_string.length()-1]='\0'; //removing last &

	// TODO: Header handling remaining

    CURL* curl; // curl object

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    struct curl_slist *header_list = NULL;
    header_list = curl_slist_append(header_list, "Content-Type: application/json");
    curl_slist_append(header_list, "Accept-Encoding: identity");
    
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);

    curl_easy_setopt(curl, CURLOPT_URL, request_string.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return response;
}
