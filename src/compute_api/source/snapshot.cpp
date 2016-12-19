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
#include "snapshot.hpp"
#include "requestify.hpp"
#include <sstream>
#include <map>
#include "src/compute_api/include/constants.hpp"

namespace snapshot
{


	pair<string,long> create_snapshot(utils::auth_var &info, const model::create_snapshot_request &req)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::CREATE_SNAPSHOT;
		params[constants::VERSION] = info.version;
		
		if(req.get_volume_id().length() == 0)
		{	
			cerr <<  "Error : Volume ID needed";
		}
		else
		{
			params[constants::VOLUME_ID] = req.get_volume_id();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> delete_snapshot(utils::auth_var &info, const model::delete_snapshot_request &req)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::DELETE_SNAPSHOT;
		params[constants::VERSION] = info.version;
		
		if(req.get_snapshot_id().length() == 0)
		{	
			cerr <<  "Error : Snapshot ID needed";
		}
		else
		{
			params[constants::SNAPSHOT_ID] = req.get_snapshot_id();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> describe_snapshots(utils::auth_var &info, const model::describe_snapshots_request &req)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::DESCRIBE_SNAPSHOTS;
		params[constants::VERSION] = info.version;

		stringstream ss;	// to convert int into string
		if((req.get_snapshot_ids())->size() != 0)
		{
			string key = constants::SNAPSHOT_ID + ".";
			for(size_t i=0 ; i<(req.get_snapshot_ids())->size() ; i++)
			{
				ss << i+1;
				params[key + ss.str()] = (*req.get_snapshot_ids())[i];
				ss.str("");
			}	
		}

		if(req.get_max_results() != -1)		// Default value -1
		{	
			ss << req.get_max_results();
			params[constants::MAX_RESULTS] = ss.str();
			ss.str("");
		}
		
		if(req.get_next_token().length() != 0)
		{
			params[constants::NEXT_TOKEN] = req.get_next_token();
		}

		if(!req.get_detail())
		{
			ss.str("false");
			params[constants::DETAIL] = ss.str();
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}
}
