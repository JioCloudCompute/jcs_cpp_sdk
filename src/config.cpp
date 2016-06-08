#include <iostream>
#include <map>
#include <string>
#include <fstream>
// TODO :read from configuration files or hard COde >??
namespace config{
	// Setting up the various endpoints of the API.
	std::map<std::string,std::string> endpoints;
	void set_up_endpoints()
	{	

		endpoints["vpc"]="https://vpc.ind-west-1.jiocloudservices.com"; // Virtual Private Cloud Endpoint
		endpoints["iam"] = "https://iam.ind-west-1.jiocloudservices.com"; // Authentication Endpoint
		endpoints["rds"] = "https://rds.ind-west-1.jiocloudservices.com"; // Data Storage Enpoint
		endpoints["dss"]= "https://dss.ind-west-1.jiocloudservices.com";// Durable Data Storage Endpoint
		endpoints["compute"] = "https://compute.ind-west-1.staging.jiocloudservices.com"; // Compute Endpoint
	}

	std::string get_service_url(std::string service_name)
	{	
		set_up_endpoints();
		return endpoints[service_name]; // return the respective service's endpoint url 
	}


	class ConfigHandler
	{
		private:
			//endpoints already
			bool secure;	// Whether the HTTP connection is secure
			bool debug;		// Debug mode

			// read this from config file 
			std::string access_key;	
			std::string secret_key;

		public:
			ConfigHandler()
			{	
				//read this from configuration file
				secure = false;
				debug = false;

				// reading keys from file 
				std::ifstream infile("config.txt");
				std::string line;
				getline(infile,line); // First Line is the access Key
				access_key = line;
				getline(infile,line); // Second Line is the secret Key
				secret_key = line; 
				infile.close();

				//set up endpoints
		
				if (access_key.empty() || secret_key.empty())
				{
				std::cout<<"Unknown Credentials:Access key or secret key not set";
				}
			}
			// Getter for access Key
			std::string get_access_key() const
			{
				return access_key;
			}
			//Getter for secret Key
			std::string get_secret_key() const
			{
				return secret_key;
			}
			bool check_secure() const
			{
				return secure;
			}
			bool check_debug() const
			{
				return debug;
			}


};

}