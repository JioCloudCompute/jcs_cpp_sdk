#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
namespace volume
{
	string describe_volumes(::http_var &info, vector<string> volume_ids  = vector<string>(),
	 				 int max_results = -1, string next_token = "", bool detail = true)
	{
		map <string, string> params;
		params["Action"] = "DescribeVolumes";
		params["Version"] = info.version;

		stringstream ss;
		if(volume_ids.size() != 0)
		{
			string key = "VolumeId.";
			for(int i=0 ; i<volume_ids.size() ; i++)
			{
				ss << i+1;
				params[key + ss.str()] = volume_ids[i];
				ss.str("");
			}	
		}

		if(max_results != -1)
		{	
			ss << max_results;
			params["MaxResults"] = ss.str();
			ss.str("");
		}
		
		if(next_token.length() != 0)
		{
			params["NextToken"] = next_token;
		}

		if(!detail)
		{
			ss.str("false");
			params["Detail"] = ss.str();
			ss.str("");
		}

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}



	string attach_volume(::http_var &info, string instance_id, string volume_id, string device)
	{
		map <string, string> params;
		params["Action"] = "AttachVolume";
		params["Version"] = info.version;
		
		if(instance_id.length() == 0)
		{	
			return "Error : Instance-Id needed";
		}
		else
		{
			params["InstanceId"] = instance_id;	
		}

		if(volume_id.length() == 0)
		{	
			return "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = volume_id;
		}

		if(device.length() == 0)
		{	
			return "Error : Device needed";
		}
		else
		{
			params["Device"] = device;
		}

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}


	string detach_volume(::http_var &info, string instance_id, string volume_id)
	{
		map <string, string> params;
		params["Action"] = "DetachVolume";
		params["Version"] = info.version;
		
		if(instance_id.length() == 0)
		{	
			return "Error : Instance-Id needed";
		}
		else
		{
			params["InstanceId"] = instance_id;	
		}

		if(volume_id.length() == 0)
		{	
			return "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = volume_id;
		}

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}

	string create_volume(::http_var &info, int size  = -1, string snapshot_id = "")
	{
		map <string, string> params;
		params["Action"] = "CreateVolume";
		params["Version"] = info.version;
		
		if(size != -1)
		{
			stringstream ss;
			ss << size;
			params["Size"] = ss.str();
		}

		if(snapshot_id.length() != 0)
		{	
			params["SnapshotId"] = snapshot_id;
		}

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}

	string delete_volume(::http_var &info, string volume_id )
	{
		map <string, string> params;
		params["Action"] = "DeleteVolume";
		params["Version"] = info.version;
		
		if(volume_id.length() == 0)
		{	
			return "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = volume_id;
		}

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}


	string show_delete_on_termination_flag(::http_var &info, string volume_id )
	{
		map <string, string> params;
		params["Action"] = "ShowDeleteOnTerminationFlag";
		params["Version"] = info.version;
		
		if(volume_id.length() == 0)
		{	
			return "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = volume_id;
		}

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}


	string update_delete_on_termination_flag(::http_var &info, string volume_id, bool delete_on_termination)
	{
		map <string, string> params;
		params["Action"] = "UpdateDeleteOnTerminationFlag";
		params["Version"] = info.version;
		
		if(volume_id.length() == 0)
		{	
			return "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = volume_id;
		}

		stringstream ss;
		if(delete_on_termination)
		{
			ss.str("True");
		}
		else
		{
			ss.str("False");
		}

		params["DeleteOnTermination"] = ss.str();
		
		return make_request(info, params);	// make_request function in "requestify.cpp"
	}
}