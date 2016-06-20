/*****************************************************************************
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
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "src/compute_api/include/model/describe_snapshots_request.hpp"
#include "src/compute_api/include/model/describe_snapshots_response.hpp"
#include "src/compute_api/include/model/delete_snapshot_request.hpp"
#include "src/compute_api/include/model/delete_snapshot_response.hpp"
#include "src/compute_api/include/model/create_snapshot_request.hpp"
#include "src/compute_api/include/model/create_snapshot_response.hpp"
#include "src/utils.cpp"
#include "src/requestify.cpp"

using namespace std;
using namespace utils;
using namespace requestify;

namespace snapshot
{
	pair<string,long> create_snapshot(utils::http_var &info, const model::create_snapshot_request &req)
	{
		map <string, string> params;
		params["Action"] = "CreateSnapshot";
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

	pair<string,long> delete_snapshot(utils::http_var &info, const model::delete_snapshot_request &req)
	{
		map <string, string> params;
		params["Action"] = "DeleteSnapshot";
		params["Version"] = info.version;
		
		if(req.get_snapshot_id().length() == 0)
		{	
			cout <<  "Error : Snapshot ID needed";
		}
		else
		{
			params["SnapshotId"] = req.get_snapshot_id();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> describe_snapshots(utils::http_var &info, const model::describe_snapshots_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeSnapshots";
		params["Version"] = info.version;

		stringstream ss;	// to convert int into string
		if((req.get_snapshot_ids())->size() != 0)
		{
			string key = "SnapshotId.";
			for(int i=0 ; i<(req.get_snapshot_ids())->size() ; i++)
			{
				ss << i+1;
				params[key + ss.str()] = (*req.get_snapshot_ids())[i];
				ss.str("");
			}	
		}

		if(req.get_max_results() != -1)		// Default value -1
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
}