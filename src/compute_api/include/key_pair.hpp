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
#ifndef KEY_PAIR_DEFINER_H
#define KEY_PAIR_DEFINER_H
#include <iostream>
#include <string>
#include "model/describe_key_pairs_response.hpp"
#include "model/create_key_pair_request.hpp"
#include "model/create_key_pair_response.hpp"
#include "model/delete_key_pair_request.hpp"
#include "model/delete_key_pair_response.hpp"
#include "model/import_key_pair_request.hpp"
#include "model/import_key_pair_response.hpp"
#include "utils.hpp"


using namespace std;

namespace key_pair
{
	pair<string,long> describe_key_pairs(utils::auth_var &info);

	pair<string,long> create_key_pair(utils::auth_var &info, const model::create_key_pair_request &req);

	pair<string,long> delete_key_pair(utils::auth_var &info, const model::delete_key_pair_request &req);

	pair<string,long> import_key_pair(utils::auth_var &info, const model::import_key_pair_request &req);

}
#endif
