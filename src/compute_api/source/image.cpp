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
#include "image.hpp"
#include <map>
#include <sstream>
#include "src/compute_api/include/constants.hpp"
#include "src/requestify.hpp"

namespace image
{
	pair<string, long> describe_images(utils::auth_var &info, const model::describe_images_request &req)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::DESCRIBE_IMAGES; // Adding action to the map params 
		params[constants::VERSION] = info.version;	// Adding version to the map params
		stringstream ss;
		string key = "ImageId.";
    size_t i = 1;
    for(std::set<std::string>::const_iterator iter = req.get_image_ids()->begin(); iter!=req.get_image_ids()->end(); ++iter)
		{
			ss << i++;
			params[key+ss.str()] = *iter;	//Adding images ids in params
			ss.str("");
		}

		return requestify::make_request(info, params);	// make_request function in 'requestify.cpp'
		
	}
}
