#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "src/compute_api/source/model/describe_instances_response.cpp"
#include "src/compute_api/source/model/describe_instances_request.cpp"
#include "src/compute_api/source/model/run_instances_response.cpp"
#include "src/compute_api/source/model/run_instances_request.cpp"
#include "src/compute_api/source/model/start_instances_response.cpp"
#include "src/compute_api/source/model/start_instances_request.cpp"
#include "src/compute_api/source/model/stop_instances_response.cpp"
#include "src/compute_api/source/model/stop_instances_request.cpp"
#include "src/compute_api/source/model/terminate_instances_response.cpp"
#include "src/compute_api/source/model/terminate_instances_request.cpp"
#include "src/compute_api/source/model/reboot_instances_response.cpp"
#include "src/compute_api/source/model/reboot_instances_request.cpp"
#include "src/compute_api/source/model/describe_instance_types_response.cpp"
#include "src/compute_api/source/model/describe_instance_types_request.cpp"
#include "src/compute_api/source/model/get_password_data_request.cpp"
#include "src/compute_api/source/model/get_password_data_response.cpp"
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>

using namespace std;

namespace instance
{
	pair<string,long> describe_instances(utils::http_var &info, const model::describe_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeInstances";
		params["Version"] = info.version;
		
		string key = "InstanceId.";
		stringstream ss;	// To convert int to string
		for(int i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		//// TODO : Add filters
		// Right now filters functionality is broken, it works only
	   	// for cases like --filters "Name=abc,Values=def"
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> describe_instance_types(utils::http_var &info, const model::describe_instance_types_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeInstanceTypes";
		params["Version"] = info.version;
		
		string key = "InstanceTypeId.";
		stringstream ss;
		for(int i=0 ; i<(req.get_instance_type_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_type_ids())[i];
			ss.str("");
		}

		//// TODO : Add filters
		// Right now filters functionality is broken, it works only
	   	// for cases like --filters "Name=abc,Values=def"
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> start_instances(utils::http_var &info, const model::start_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "StartInstances";
		params["Version"] = info.version;
		
		if((req.get_instance_ids())->size() == 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(int i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> stop_instances(utils::http_var &info, const model::stop_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "StopInstances";
		params["Version"] = info.version;

		if((req.get_instance_ids())->size() == 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(int i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> reboot_instances(utils::http_var &info, const model::reboot_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "RebootInstances";
		params["Version"] = info.version;
		
		if((req.get_instance_ids())->size()== 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(int i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> terminate_instances(utils::http_var &info, const model::terminate_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "TerminateInstances";
		params["Version"] = info.version;
		
		if((req.get_instance_ids())->size() == 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(int i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}



	pair<string,long> run_instances(utils::http_var &info, const model::run_instances_request &req )
	{
		map <string, string> params;
		params["Action"] = "RunInstances";
		params["Version"] = info.version;

		if(req.get_image_id().length() == 0)
		{	
			cout << "Error : Image-Id needed";
		}
		else
		{
			params["ImageId"] = req.get_image_id();
		}

		if(req.get_instance_type_id().length() == 0)
		{	
			cout << "Error : Instance-Type-Id needed";
		}
		else
		{
			params["InstanceTypeId"] = req.get_instance_type_id();
		}

		if((req.get_block_device_mapping())->size() != 0)
		{
			string key = "BlockDeviceMapping.";
			stringstream ss,ss1;
			for(int i=0 ; i<(req.get_block_device_mapping())->size() ; i++)
			{
				ss << i+1;
				params[key+ss.str()+".DeviceName"] = (*req.get_block_device_mapping())[i].device_name;
				(*req.get_block_device_mapping())[i].delete_on_termination ? ss1.str("true") : ss1.str("false");
				params[key+ss.str()+".DeleteOnTermination"] = ss1.str();
				ss1.str("");
				ss1 << (*req.get_block_device_mapping())[i].volume_size;
				params[key+ss.str()+".VolumeSize"] = ss1.str();
				ss1.str("");
				ss.str("");
			}
		}

		if(req.get_instance_count()!=-1)
		{
			params["InstanceCount"] = req.get_instance_count();
		}

		if(req.get_subnet_id()!="")
		{
			params["SubnetId"] = req.get_subnet_id();
		}

		if(req.get_private_ip_address()!="")
		{
			params["PrivateIPAddress"] = req.get_private_ip_address();
		}

		if(!(req.get_security_group_ids())->empty())
		{
			for(int i=0 ; i<(req.get_security_group_ids())->size() ; i++)
			{
				string key = "SecurityGroupId.0";
				key[key.length()-1] = i+1;
				params[key] = (*req.get_security_group_ids())[i];
			}		
		}

		if(req.get_key_name()!="")
		{
			params["KeyName"] = req.get_key_name();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string, long> get_password_data(utils::http_var &info, const model::get_password_data_request &req)

	{	
		map<string , string > params;
		params["Action"] = "GetPasswordData";
		params["Version"] = info.version;

		if(req.get_instance_id().length() == 0){
			cout<<"Instance-ID is Required"<<endl;
		}
		else{
			params["InstanceId"] = req.get_instance_id();
		} 

		return requestify::make_request(info,params);

	}

	void decrypt_password(const char* encrypted_password, const std::string &private_key_file, const std::string passphrase)
	{
		//cout<<encrypted_password<<endl;
		
		RSA *rsa = utils::import_ssh_key(private_key_file, passphrase);
		// cout<<"back"<<endl;
		//unsigned char* password_data = (unsigned char*)utils::base64decode(encrypted_password , strlen(encrypted_password));
		// unsigned char* password_data = (unsigned char*)"UrJ4L8yhqbdRzMdkw162sHqJd792ksIQnku8e8+hR6uTFGC7Iqra95OIepsjdlzPNt8rs906EUroEw40aK9j9Y0J4odXH3RuZr3sG/DMvc7AdQlfCd4LKd5c2HM4yMRsySWRaR31rM8Ke8GSzDcjDypy5QOFyMUD0cSUdCZTKP0vE7Kzd6m7vBQguo/NcZK/2gFC1vX3ZWNlpgjr8FioAZScoK5TRkXq/MqQo5PlPr2WVFhMZyPQxAZh/boy0/j0QRqSrZeKTCzPJ0xBWYLWKAdq4xLi9XinJonyaNJ/W9tJRgsOdFourncG6jB9iM1KQ1isbhPh2buysFG4g/NoIw==";
		
		unsigned char * password_data =(unsigned char*) utils::base64decode("p05Oey3oqtQOuQhL8VzbbYA8N7cpP9fzeklGEekcvUI9DYbCXioSRbZFoP3ef2IGtggWe7TJVLy3ErzlXOHoyfSF4YF8M2g2WOq7+FlBmfhIOyfGpjmBczn08zorCRrP+yUDPo3wQ4Rt7nvFheDZPli7ttdOXwBJAie/RMvyGLG8QvPYqrjTonZe5i3KLraYgQlBdJRSTyZfcu6q2qiLWxrH5pzFQeVsF25DqQeUorjtnoqy9D5/pC+7LtU5BXl4OnpHkVif5PjAJ2tOaDPAurQI67+EyxI9ydQk/7t3VRk7dHE57NHkltigVkkgUS3KWGvYW0erQfFNr6dwqr5uig==\n",344);
		unsigned char* to = new unsigned char[strlen((const char*)password_data)+1];
		int padding = RSA_PKCS1_PADDING;
		
		// cout<<RSA_size(rsa) - 11<<endl;
		// cout<<strlen((const char*)password_data)<<endl;	
		int res = RSA_private_decrypt(strlen((const char*)password_data),password_data,to, rsa, padding);
		//cout<<res<<endl;
		
		printf("final: %s\n : final\n",to);
		// std::string encrypted_data = "hello";

		// char ciphertext[512];

		// return ciphertext;
		/*unsigned char *plaintext;
		if(RSA_public_decrypt(ciphertext.length(), ciphertext.c_str(), rsa, RSA_PKCS1_PADDING) != -1)
		{

		}
		else
		{
			cout<<"Error"<<endl;
		}
		*/

	}

}