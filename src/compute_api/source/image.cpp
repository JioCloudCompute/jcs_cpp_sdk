#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;
using namespace utils;
using namespace requestify;

namespace image
{
	string describe_images(utils::http_var &info, vector<string> image_ids = vector<string>())
	{
		map <string, string> params;
		params["Action"] = "DescribeImages";
		params["Version"] = info.version;
		stringstream ss;
		string key = "ImageId.";
		for(int i=0 ; i<image_ids.size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = image_ids[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// make_request function in 'requestify.cpp'
	}
}