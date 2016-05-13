#include <string>
#include <map>
struct auth_var{
	char url[512];
	char verb[8];
	char access_key[128];
	char secret_key[128];
	char headers[128];
	char path[128];
	char protocol[8];
	char host[128];
	int port;
};

struct http_var{
	char url[512];
	char verb[8];
	char version[16];
	char headers[128];
	
};

char[8] get_protocol(char url[512])
{	
	//EXTRA CHECK REQUIRED Regexp
	string url_ = url;
	return url.substr(0,5);   //https
}
char[128] get_host(char url[128])
{
	string host_ = url;
	return host.substr(8);
}
void populate_params(map<std::string,std::string> &params)
{
	
}

