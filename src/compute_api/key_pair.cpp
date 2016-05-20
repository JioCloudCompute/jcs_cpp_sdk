#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
namespace key_pair
{
	string describe_key_pairs(::http_var &info)
	{
		map <string, string> params;
		params["Action"] = "DescribeKeyPairs";
		params["Version"] = info.version;
		
		return make_request(info, params);	// make_request function in "requestify.cpp"
	}


	string create_key_pair(::http_var &info, string key_name)
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

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}

	string delete_key_pair(::http_var &info, string key_name)
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

		return make_request(info, params);	// make_request function in "requestify.cpp"
	}

	string import_key_pair(::http_var &info, string key_name, string public_key_material)
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

		return make_request(info, params);	// make_request function in "requestify.cpp"	
	}
}