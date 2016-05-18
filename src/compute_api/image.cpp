#include "utils.cpp"
#include "requestify.cpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

string describe_images(const http_var &info, vector<string> image_ids = vector<string>())
{
	map <string, string> params;
	params['Action'] = "DescribeImages";
	params['Version'] = info.version;
	
	for(int i=0 ; i<image_ids.size() ; i++)
	{
		string key = "ImageId.0";
		key[key.length()-1] = i+1;
		params[key] = image_ids[i];
	}

	return make_request(info, params);	// make_request function in 'requestify.cpp'
}
