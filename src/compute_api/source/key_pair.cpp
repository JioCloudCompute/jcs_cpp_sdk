#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "src/compute_api/source/model/describe_key_pairs_response.cpp"
#include "src/compute_api/source/model/create_key_pair_request.cpp"
#include "src/compute_api/source/model/create_key_pair_response.cpp"
#include "src/compute_api/source/model/delete_key_pair_request.cpp"
#include "src/compute_api/source/model/delete_key_pair_response.cpp"
#include "src/compute_api/source/model/import_key_pair_request.cpp"
#include "src/compute_api/source/model/import_key_pair_response.cpp"

using namespace std;
using namespace utils;
using namespace requestify;

namespace key_pair
{
	pair<string,long> describe_key_pairs(utils::http_var &info)
	{
		map <string, string> params;
		params["Action"] = "DescribeKeyPairs";
		params["Version"] = info.version;
		
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> create_key_pair(utils::http_var &info, model::create_key_pair_request &req)
	{
		map <string, string> params;
		params["Action"] = "CreateKeyPair";
		params["Version"] = info.version;
		
		if(req.get_key_name().length() == 0)
		{	
			cout <<  "Error : Key-Name needed";
		}
		else
		{
			params["KeyName"] = req.get_key_name();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> delete_key_pair(utils::http_var &info, model::delete_key_pair_request &req)
	{
		map <string, string> params;
		params["Action"] = "DeleteKeyPair";
		params["Version"] = info.version;

		if(req.get_key_name().length() == 0)
		{	
			cout <<  "Error : KeyName needed";
		}
		else
		{
			params["KeyName"] = req.get_key_name();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> import_key_pair(utils::http_var &info, model::import_key_pair_request &req)
	{
		map <string, string> params;
		params["Action"] = "ImportKeyPair";
		params["Version"] = info.version;

		if(req.get_key_name().length() == 0)
		{	
			cout <<  "Error : KeyName needed";
		}
		else
		{
			params["KeyName"] = req.get_key_name();
		}


		if(req.get_public_key_material().length() == 0)
		{	
			cout <<  "Error : Public key material needed";
		}
		else
		{
			params["PublicKeyMaterial"] = req.get_public_key_material();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"	
	}
}