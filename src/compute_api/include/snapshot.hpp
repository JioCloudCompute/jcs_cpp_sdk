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
#ifndef SNAPSHOT_DEFINER_H
#define SNAPSHOT_DEFINER_H
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "src/compute_api/include/model/describe_snapshots_request.hpp"
#include "src/compute_api/include/model/describe_snapshots_response.hpp"
#include "src/compute_api/include/model/delete_snapshot_request.hpp"
#include "src/compute_api/include/model/delete_snapshot_response.hpp"
#include "src/compute_api/include/model/create_snapshot_request.hpp"
#include "src/compute_api/include/model/create_snapshot_response.hpp"
#include "src/utils.hpp"
#include "src/requestify.hpp"

using namespace std;
using namespace utils;
using namespace requestify;

namespace snapshot
{
	pair<string,long> create_snapshot(utils::http_var &info, const model::create_snapshot_request &req);
	

	pair<string,long> delete_snapshot(utils::http_var &info, const model::delete_snapshot_request &req);
	

	pair<string,long> describe_snapshots(utils::http_var &info, const model::describe_snapshots_request &req);
	
}
#endif