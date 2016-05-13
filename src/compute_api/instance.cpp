#include "utils.cpp"
#include "requestify.cpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

string describe_instances(http_var &info, vector<string> instance_ids  = vector<string>())
{
	map <string, string> params;
	params['Action'] = "DescribeInstances";
	params['Version'] = info.version;
	
	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		string key = "InstanceId.0";
		key[key.length()-1] = i+1;
		params[key] = instance_ids[i];
	}

	//// TODO : Add filters
	// Right now filters functionality is broken, it works only
   	// for cases like --filters "Name=abc,Values=def"
	return make_request(info, params);	// make_request function in 'requestify.cpp'
}



string start_instances(http_var &info, vector<string> instance_ids)
{
	map <string, string> params;
	params['Action'] = "StartInstances";
	params['Version'] = info.version;
	
	if(instance_ids.size() == 0)
	{	
		cout<<"Instance-Id needed"<<endl;
		//// TODO :
		// Raise exeception
	}


	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		string key = "InstanceId.0";
		key[key.length()-1] = i+1;
		params[key] = instance_ids[i];
	}

	return make_request(info, params);	// make_request function in 'requestify.cpp'
}

string stop_instances(http_var &info, vector<string> instance_ids, bool force = false)
{
	map <string, string> params;
	params['Action'] = "StopInstances";
	params['Version'] = info.version;

	// Confirm with Anant about force
	// if(force)
	// {
	// 	params['Force'] = "TRUE";
	// }
	// else
	// {
	// 	params['Force'] = "FALSE";
	// }
	
	if(instance_ids.size() == 0)
	{	
		cout<<"Instance-Id needed"<<endl;
		//// TODO :
		// Raise exeception
	}


	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		string key = "InstanceId.0";
		key[key.length()-1] = i+1;
		params[key] = instance_ids[i];
	}

	return make_request(info, params);	// make_request function in 'requestify.cpp'
}


string reboot_instances(http_var &info, vector<string> instance_ids)
{
	map <string, string> params;
	params['Action'] = "RebootInstances";
	params['Version'] = info.version;
	
	if(instance_ids.size() == 0)
	{	
		cout<<"Instance-Id needed"<<endl;
		//// TODO :
		// Raise exeception
	}


	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		string key = "InstanceId.0";
		key[key.length()-1] = i+1;
		params[key] = instance_ids[i];
	}

	return make_request(info, params);	// make_request function in 'requestify.cpp'
}


string terminate_instances(http_var &info, vector<string> instance_ids)
{
	map <string, string> params;
	params['Action'] = "TerminateInstances";
	params['Version'] = info.version;
	
	if(instance_ids.size() == 0)
	{	
		cout<<"Instance-Id needed"<<endl;
		//// TODO :
		// Raise exeception
	}


	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		string key = "InstanceId.0";
		key[key.length()-1] = i+1;
		params[key] = instance_ids[i];
	}

	return make_request(info, params);	// make_request function in 'requestify.cpp'
}

string run_instances(http_var &info, vector<string> instance_type_id)
{
	map <string, string> params;
	params['Action'] = "StartInstances";
	params['Version'] = info.version;
	
	if(instance_ids.size() == 0)
	{	
		cout<<"Instance-Id needed"<<endl;
		//// TODO :
		// Raise exeception
	}


	for(int i=0 ; i<instance_ids.size() ; i++)
	{
		string key = "InstanceId.0";
		key[key.length()-1] = i+1;
		params[key] = instance_ids[i];
	}

	return make_request(info, params);	// make_request function in 'requestify.cpp'
}



