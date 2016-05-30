#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "src/compute_api/source/model/create_volume_request.cpp"
#include "src/compute_api/source/model/create_volume_response.cpp"
#include "src/compute_api/source/model/delete_volume_request.cpp"
#include "src/compute_api/source/model/delete_volume_response.cpp"
#include "src/compute_api/source/model/attach_volume_request.cpp"
#include "src/compute_api/source/model/attach_volume_response.cpp"
#include "src/compute_api/source/model/detach_volume_request.cpp"
#include "src/compute_api/source/model/detach_volume_response.cpp"
#include "src/compute_api/source/model/describe_volumes_request.cpp"
#include "src/compute_api/source/model/describe_volumes_response.cpp"
#include "src/compute_api/source/model/show_delete_on_termination_flag_request.cpp"
#include "src/compute_api/source/model/show_delete_on_termination_flag_response.cpp"
#include "src/compute_api/source/model/update_delete_on_termination_flag_request.cpp"
#include "src/compute_api/source/model/update_delete_on_termination_flag_response.cpp"

using namespace std;
using namespace utils;
using namespace requestify;
using namespace model;

namespace volume
{
	pair<string,long> describe_volumes(utils::http_var &info, const model::describe_volumes_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeVolumes";
		params["Version"] = info.version;

		stringstream ss;
		if((req.get_volume_ids())->size() != 0)
		{
			string key = "VolumeId.";
			for(int i=0 ; i<(req.get_volume_ids())->size() ; i++)
			{
				ss << i+1;
				params[key + ss.str()] = (*req.get_volume_ids())[i];
				ss.str("");
			}	
		}

		if(req.get_max_results() != -1)
		{	
			ss << req.get_max_results();
			params["MaxResults"] = ss.str();
			ss.str("");
		}
		
		if(req.get_next_token().length() != 0)
		{
			params["NextToken"] = req.get_next_token();
		}

		if(!req.get_detail())
		{
			ss.str("false");
			params["Detail"] = ss.str();
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}



	pair<string,long> attach_volume(utils::http_var &info, const model::attach_volume_request &req)
	{
		map <string, string> params;
		params["Action"] = "AttachVolume";
		params["Version"] = info.version;
		
		if(req.get_instance_id().length() == 0)
		{	
			cout <<  "Error : Instance-Id needed";
		}
		else
		{
			params["InstanceId"] = req.get_instance_id();	
		}

		if(req.get_volume_id().length() == 0)
		{	
			cout <<  "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = req.get_volume_id();
		}

		if(req.get_device().length() == 0)
		{	
			cout <<  "Error : Device needed";
		}
		else
		{
			params["Device"] = req.get_device();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> detach_volume(utils::http_var &info, const model::detach_volume_request &req)
	{
		map <string, string> params;
		params["Action"] = "DetachVolume";
		params["Version"] = info.version;
		
		if(req.get_instance_id().length() != 0)
		{
			params["InstanceId"] = req.get_instance_id();	
		}

		if(req.get_volume_id().length() == 0)
		{	
			cout <<  "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = req.get_volume_id();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> create_volume(utils::http_var &info, model::create_volume_request &req)
	{
		map <string, string> params;
		params["Action"] = "CreateVolume";
		params["Version"] = info.version;

		if(req.get_size() == -1 && req.get_snapshot_id().length() == 0)
		{
			cout <<  "Parameters missing, Atleast one of them needed";
		}
		
		if(req.get_size() != -1)
		{
			stringstream ss;
			ss << req.get_size();
			params["Size"] = ss.str();
		}

		if(req.get_snapshot_id().length() != 0)
		{	
			params["SnapshotId"] = req.get_snapshot_id();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> delete_volume(utils::http_var &info, const model::delete_volume_request &req)
	{
		map <string, string> params;
		params["Action"] = "DeleteVolume";
		params["Version"] = info.version;
		
		if(req.get_volume_id().length() == 0)
		{	
			cout <<  "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = req.get_volume_id();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> show_delete_on_termination_flag(utils::http_var &info, const model::show_delete_on_termination_flag_request &req)
	{
		map <string, string> params;
		params["Action"] = "ShowDeleteOnTerminationFlag";
		params["Version"] = info.version;
		
		if(req.get_volume_id().length() == 0)
		{	
			cout <<  "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = req.get_volume_id();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> update_delete_on_termination_flag(utils::http_var &info, const model::update_delete_on_termination_flag_request &req)
	{
		map <string, string> params;
		params["Action"] = "UpdateDeleteOnTerminationFlag";
		params["Version"] = info.version;
		
		if(req.get_volume_id().length() == 0)
		{	
			cout <<  "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = req.get_volume_id();
		}

		stringstream ss;
		if(req.get_delete_on_termination())
		{
			ss.str("True");
		}
		else
		{
			ss.str("False");
		}

		params["DeleteOnTermination"] = ss.str();
		
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}
}