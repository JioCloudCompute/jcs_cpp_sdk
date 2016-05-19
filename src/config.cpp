#include <iostream>
#include <map>
#include <string>
#include <fstream>
// TODO :read from configuration files or hard COde >??
std::map<std::string,std::string> endpoints;

void set_up_endpoints()
{	

	endpoints["vpc"]="https://vpc.ind-west-1.jiocloudservices.com";
	endpoints["iam"] = "https://iam.ind-west-1.jiocloudservices.com";
	endpoints["rds"] = "https://rds.ind-west-1.jiocloudservices.com";
	endpoints["dss"]= "https://dss.ind-west-1.jiocloudservices.com";
	endpoints["compute"] = "https://compute.ind-west-1.staging.jiocloudservices.com";
}

std::string get_service_url(std::string service_name)
{	
	set_up_endpoints();
	return endpoints[service_name];
}


class ConfigHandler
{
	private:
		//endpoints already
		bool secure;
		bool debug;

		// read this from config file 
		std::string access_key;
		std::string secret_key;

	public:
		ConfigHandler()
		{	
			//read this from configuration file
			secure = true;
			debug = false;
			// reading keys from file
			std::ifstream infile("config.txt");
			std::string line;
			getline(infile,line);
			access_key = line;
			getline(infile,line);
			secret_key = line;
			infile.close();

			//set up endpoints
	
			if (access_key.empty() || secret_key.empty())
			{
			std::cout<<"Unknown Credentials:Access key or secret key not set";
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


};