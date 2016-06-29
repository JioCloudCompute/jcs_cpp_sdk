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
#include "src/compute_api/include/key_pair.hpp"
#include "src/requestify.hpp"
#include <sstream>
#include <map>
#include <vector>
#include "src/compute_api/include/constants.hpp"

namespace key_pair
{
	pair<string,long> describe_key_pairs(utils::http_var &info)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::DESCRIBE_KEY_PAIRS;
		params[constants::VERSION] = info.version;
		
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> create_key_pair(utils::http_var &info, const model::create_key_pair_request &req)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::CREATE_KEY_PAIR;
		params[constants::VERSION] = info.version;
		
		if(req.get_key_name().length() == 0)
		{	
			cerr <<  "Error : Key-Name needed";
		}
		else
		{
			params[constants::KEY_NAME] = req.get_key_name();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> delete_key_pair(utils::http_var &info, const model::delete_key_pair_request &req)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::DELETE_KEY_PAIR;
		params[constants::VERSION] = info.version;

		if(req.get_key_name().length() == 0)
		{	
			cerr <<  "Error : KeyName needed";
		}
		else
		{
			params[constants::KEY_NAME] = req.get_key_name();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> import_key_pair(utils::http_var &info, const model::import_key_pair_request &req)
	{
		map <string, string> params;
		params[constants::ACTION] = constants::IMPORT_KEY_PAIR;
		params[constants::VERSION] = info.version;

		if(req.get_key_name().length() == 0)
		{	
			cerr <<  "Error : KeyName needed";
		}
		else
		{
			params[constants::KEY_NAME] = req.get_key_name();
		}


		if(req.get_public_key_material().length() == 0)
		{	
			cerr <<  "Error : Public key material needed";
		}
		else
		{
			params[constants::PUBLIC_KEY_MATERIAL] = req.get_public_key_material();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"	
	}
}