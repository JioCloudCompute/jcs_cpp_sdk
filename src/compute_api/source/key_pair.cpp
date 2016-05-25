#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "src/compute_api/source/model/describe_key_pairs_request.cpp"
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
	string describe_key_pairs(utils::http_var &info)
	{
		map <string, string> params;
		params["Action"] = "DescribeKeyPairs";
		params["Version"] = info.version;
		
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	string create_key_pair(utils::http_var &info, string key_name)
	{
		map <string, string> params;
		params["Action"] = "CreateKeyPair";
		params["Version"] = info.version;
		
		if(key_name.length() == 0)
		{	
			return "Error : Key-Name needed";
		}
		else
		{
			params["KeyName"] = key_name;
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	string delete_key_pair(utils::http_var &info, string key_name)
	{
		map <string, string> params;
		params["Action"] = "DeleteKeyPair";
		params["Version"] = info.version;

		if(key_name.length() == 0)
		{	
			return "Error : KeyName needed";
		}
		else
		{
			params["KeyName"] = key_name;
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	string import_key_pair(utils::http_var &info, string key_name, string public_key_material)
	{
		map <string, string> params;
		params["Action"] = "ImportKeyPair";
		params["Version"] = info.version;

		if(key_name.length() == 0)
		{	
			return "Error : KeyName needed";
		}
		else
		{
			params["KeyName"] = key_name;
		}


		if(public_key_material.length() == 0)
		{	
			return "Error : Public key material needed";
		}
		else
		{
			params["PublicKeyMaterial"] = public_key_material;
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"	
	}
}