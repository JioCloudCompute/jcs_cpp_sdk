#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
using namespace utils;
using namespace requestify;

namespace snapshot
{
	string create_snapshot(utils::http_var &info, string volume_id)
	{
		map <string, string> params;
		params["Action"] = "CreateSnapshot";
		params["Version"] = info.version;
		
		if(volume_id.length() == 0)
		{	
			return "Error : Volume ID needed";
		}
		else
		{
			params["VolumeId"] = volume_id;
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	string delete_snapshot(utils::http_var &info, string snapshot_id)
	{
		map <string, string> params;
		params["Action"] = "DeleteSnapshot";
		params["Version"] = info.version;
		
		if(snapshot_id.length() == 0)
		{	
			return "Error : Snapshot ID needed";
		}
		else
		{
			params["SnapshotId"] = snapshot_id;
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	string describe_snapshots(utils::http_var &info, vector<string> snapshot_ids  = vector<string>(),
	 				 int max_results = -1, string next_token = "", bool detail = true)
	{
		map <string, string> params;
		params["Action"] = "DescribeSnapshots";
		params["Version"] = info.version;

		stringstream ss;
		if(snapshot_ids.size() != 0)
		{
			string key = "SnapshotId.";
			for(int i=0 ; i<snapshot_ids.size() ; i++)
			{
				ss << i+1;
				params[key + ss.str()] = snapshot_ids[i];
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

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}
}