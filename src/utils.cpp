#include <string>
#include <map>
#include <string>

struct auth_var{
	char url[512];
	char verb[8];
	char access_key[128];
	char secret_key[128];
	char headers[128];
	char path[128];
	char protocol[8];
	char host[128];
	char port[8];
	//copy constructor

};

struct http_var{
	char url[512];
	char verb[8];
	char version[16];
	char headers[128];
	
};

struct block_device_mapping{
	std::string device_name;
	bool delete_on_termination;
	int volume_size;
};

std::string get_protocol(char url[512])
{	
	//EXTRA CHECK REQUIRED Regexp
	std::string url_ = url;
	return url_.substr(0,5);   //https
}

std::string get_host(char url[128])
{
	std::string host_ = url;
	return host_.substr(8);
}


