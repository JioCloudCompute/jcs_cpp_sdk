/*`****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
#include "volume.hpp"
#include "requestify.hpp"
#include <sstream>
#include <map>


namespace volume{

	pair<string,long> describe_volumes(utils::auth_var &info, const model::describe_volumes_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeVolumes";	// Adding action to map params
		params["Version"] = info.version;	// Adding version to map params

		stringstream ss;					// To convert int int string
		if((req.get_volume_ids())->size() != 0)
		{
			string key = "VolumeId.";
			for(size_t i=0 ; i<(req.get_volume_ids())->size() ; i++)
			{
				ss << i+1;
				params[key + ss.str()] = (*req.get_volume_ids())[i];
				ss.str("");					// To prevent appending// To convert int int string
			}	
		}

		if(req.get_max_results() != -1)		// Default value set as -1
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



	pair<string,long> attach_volume(utils::auth_var &info, const model::attach_volume_request &req)
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


	pair<string,long> detach_volume(utils::auth_var &info, const model::detach_volume_request &req)
	{
		map <string, string> params;
		params["Action"] = "DetachVolume";
		params["Version"] = info.version;
		
		if(req.get_instance_id().length())
		{
			params["InstanceId"] = req.get_instance_id();
		}

		if(req.get_volume_id().length())
		{
			params["VolumeId"] = req.get_volume_id();
		}
    params["Force"] = req.get_force()?"True":"False";

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> create_volume(utils::auth_var &info, const model::create_volume_request &req)
	{
		map <string, string> params;
		params["Action"] = "CreateVolume";
		params["Version"] = info.version;

		if(req.get_size() == -1 && req.get_snapshot_id().length() == 0)		// Atleast one o size or snapshot is required
		{
			cout <<  "Parameters missing, Atleast one of snapshotId or size is needed";
		}
		
		if(req.get_size() != -1)	// Default size = -1
		{
			stringstream ss;
			ss << req.get_size();
			params["Size"] = ss.str();
		}

		if(req.get_snapshot_id().length() != 0)
		{	
			params["SnapshotId"] = req.get_snapshot_id();
		}

    params["Encrypted"] = (int)!!req.get_encrypted();

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> delete_volume(utils::auth_var &info, const model::delete_volume_request &req)
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


	pair<string,long> show_delete_on_termination_flag(utils::auth_var &info, const model::show_delete_on_termination_flag_request &req)
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


	pair<string,long> update_delete_on_termination_flag(utils::auth_var &info, const model::update_delete_on_termination_flag_request &req)
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
