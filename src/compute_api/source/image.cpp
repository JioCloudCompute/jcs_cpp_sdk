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