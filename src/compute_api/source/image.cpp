#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "src/compute_api/source/model/describe_images_request.cpp"
#include "src/compute_api/source/model/describe_images_response.cpp"


using namespace std;

namespace image
{
	pair<string, long> describe_images(utils::http_var &info, const model::describe_images_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeImages"; // Adding action to the map params 
		params["Version"] = info.version;	// Adding version to the map params
		stringstream ss;
		string key = "ImageId.";
		for(int i=0 ; i<(req.get_image_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_image_ids())[i];	//Adding images ids in param		s
			ss.str("");
		}

		return requestify::make_request(info, params);	// make_request function in 'requestify.cpp'
		
	}
}