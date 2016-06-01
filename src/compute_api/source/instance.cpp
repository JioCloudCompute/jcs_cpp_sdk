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

		if(req.get_instance_id().length() == 0)
			cout<<"Instance-ID is Required"<<endl;
		else params["InstanceID"] = req.get_instance_id();

		return requestify::make_request(info,params);

	}

}