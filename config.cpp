#include <iostream>
#include <map>

// TODO :read from configuration files 
std::map<std::string,std::string> endpoints = {{'vpc','https://vpc.ind-west-1.jiocloudservices.com/'},
{'iam','https://iam.ind-west-1.jiocloudservices.com/'},
{'rds','https://rds.ind-west-1.jiocloudservices.com/'},
{'dss','https://dss.ind-west-1.jiocloudservices.com/'},
{'compute','https://compute.ind-west-1.jiocloudservices.com/'}}

class ConfigHandler()
{
	private:
		//endpoints already
		bool secure
		bool debug

		// read this from config file 
		std::string access_key;
		std::string secret_key;

	public::
		ConfigHandler()
		{	
			//read this from configuration file
			secure = true;
			debug = false;
			access_key +="";
			secret_key += "";
			
			if (access_key.empty() || secret_key.empty())
			{
			std::cout<<"Unknown Credentials:Acess key or secret key not set";
			}
		}

		std::string get_access_key()
		{
			return access_key;
		}
		std::string get_secret_key()
		{
			return secret_key;
		}
		bool check_secure()
		{
			return secure;
		}
		bool check_debug()
		{
			return debug;
		}

}