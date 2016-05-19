#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

string describe_instances(::http_var &info, vector<string> instance_ids  = vector<string>())
{
	map <string, string> params;
	params["Action"] = "DescribeInstances";
	params["Version"] = info.version;
	
	string key = "InstanceId.";
	stringstream ss;
	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		ss << i+1;
		params[key + ss.str()] = instance_ids[i];
		ss.str("");
	}

	//// TODO : Add filters
	// Right now filters functionality is broken, it works only
   	// for cases like --filters "Name=abc,Values=def"
	return make_request(info, params);	// make_request function in "requestify.cpp"
}

string describe_instance_types(::http_var &info, vector<string> instance_type_ids  = vector<string>())
{
	map <string, string> params;
	params["Action"] = "DescribeInstanceTypes";
	params["Version"] = info.version;
	
	string key = "InstanceTypeId.";
	stringstream ss;
	for(int i=0 ; i<instance_type_ids.size() ; i++)
	{
		ss << i+1;
		params[key + ss.str()] = instance_type_ids[i];
		ss.str("");
	}

	//// TODO : Add filters
	// Right now filters functionality is broken, it works only
   	// for cases like --filters "Name=abc,Values=def"
	return make_request(info, params);	// make_request function in "requestify.cpp"
}

string start_instances(::http_var &info, vector<string> instance_ids)
{
	map <string, string> params;
	params["Action"] = "StartInstances";
	params["Version"] = info.version;
	
	if(instance_ids.size() == 0)
	{	
		return "Error : Instance-Id needed";
	}

	string key = "InstanceId.";
	stringstream ss;
	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		ss << i+1;
		params[key + ss.str()] = instance_ids[i];
		ss.str("");
	}

	return make_request(info, params);	// make_request function in "requestify.cpp"
}

string stop_instances(::http_var &info, vector<string> instance_ids)
{
	map <string, string> params;
	params["Action"] = "StopInstances";
	params["Version"] = info.version;

	if(instance_ids.size() == 0)
	{	
		return "Error : Instance-Id needed";
	}

	string key = "InstanceId.";
	stringstream ss;
	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		ss << i+1;
		params[key + ss.str()] = instance_ids[i];
		ss.str("");
	}

	return make_request(info, params);	// make_request function in "requestify.cpp"
}


string reboot_instances(::http_var &info, vector<string> instance_ids)
{
	map <string, string> params;
	params["Action"] = "RebootInstances";
	params["Version"] = info.version;
	
	if(instance_ids.size() == 0)
	{	
		return "Error : Instance-Id needed";
	}

	string key = "InstanceId.";
	stringstream ss;
	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		ss << i+1;
		params[key + ss.str()] = instance_ids[i];
		ss.str("");
	}

	return make_request(info, params);	// make_request function in "requestify.cpp"
}


string terminate_instances(::http_var &info, vector<string> instance_ids)
{
	map <string, string> params;
	params["Action"] = "TerminateInstances";
	params["Version"] = info.version;
	
	if(instance_ids.size() == 0)
	{	
		return "Error : Instance-Id needed";
	}

	string key = "InstanceId.";
	stringstream ss;
	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		ss << i+1;
		params[key + ss.str()] = instance_ids[i];
		ss.str("");
	}

	return make_request(info, params);	// make_request function in "requestify.cpp"
}


string run_instances(::http_var &info, string image_id, string instance_type_id, 
					vector<struct block_device_mapping> blocks = vector<struct block_device_mapping>(),
 					int instance_count = 1, string subnet_id = "", string private_ip_address = "",
 					vector<string> security_group_ids = vector<string>(), string key_name = "" )
{
	map <string, string> params;
	params["Action"] = "StartInstances";
	params["Version"] = info.version;

	if(image_id.length() == 0)
	{	
		return "Error : Image-Id needed";
	}
	else
	{
		params["ImageId"] = image_id;
	}

	if(instance_type_id.length() == 0)
	{	
		return "Error : Instance-Type-Id needed";
	}
	else
	{
		params["InstanceTypeId"] = instance_type_id;
	}

	if(blocks.size() != 0)
	{
		string key = "BlockDeviceMapping.";
		stringstream ss,ss1;
		for(int i=0 ; i<blocks.size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()+".DeviceName"] = blocks[i].device_name;
			blocks[i].delete_on_termination ? ss1.str("true") : ss1.str("false");
			params[key+ss.str()+".DeleteOnTermination"] = ss1.str();
			ss1.str("");
			ss1 << blocks[i].volume_size;
			params[key+ss.str()+".VolumeSize"] = ss1.str();
			ss1.str("");
			ss.str("");
		}
	}

	if(instance_count!=1)
	{
		params["InstanceCount"] = instance_count;
	}

	if(subnet_id!="")
	{
		params["SubnetId"] = subnet_id;
	}

	if(private_ip_address!="")
	{
		params["PrivateIPAddress"] = private_ip_address;
	}

	if(!security_group_ids.empty())
	{
		for(int i=0 ; i<security_group_ids.size() ; i++)
		{
			string key = "SecurityGroupId.0";
			key[key.length()-1] = i+1;
			params[key] = security_group_ids[i];
		}		
	}

	if(key_name!="")
	{
		params["KeyName"] = key_name;
	}

	return make_request(info, params);	// make_request function in "requestify.cpp"
}