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
#ifndef VOLUME_DEFINER_H
#define VOLUME_DEFINER_H
#include <iostream>
#include <string>
#include "src/compute_api/include/model/create_volume_request.hpp"
#include "src/compute_api/include/model/create_volume_response.hpp"
#include "src/compute_api/include/model/delete_volume_request.hpp"
#include "src/compute_api/include/model/delete_volume_response.hpp"
#include "src/compute_api/include/model/attach_volume_request.hpp"
#include "src/compute_api/include/model/attach_volume_response.hpp"
#include "src/compute_api/include/model/detach_volume_request.hpp"
#include "src/compute_api/include/model/detach_volume_response.hpp"
#include "src/compute_api/include/model/describe_volumes_request.hpp"
#include "src/compute_api/include/model/describe_volumes_response.hpp"
#include "src/compute_api/include/model/show_delete_on_termination_flag_request.hpp"
#include "src/compute_api/include/model/show_delete_on_termination_flag_response.hpp"
#include "src/compute_api/include/model/update_delete_on_termination_flag_request.hpp"
#include "src/compute_api/include/model/update_delete_on_termination_flag_response.hpp"
#include "src/utils.hpp"

using namespace std;

namespace volume
{
	pair<string,long> describe_volumes(utils::http_var &info, const model::describe_volumes_request &req);

	pair<string,long> attach_volume(utils::http_var &info, const model::attach_volume_request &req);

	pair<string,long> detach_volume(utils::http_var &info, const model::detach_volume_request &req);

	pair<string,long> create_volume(utils::http_var &info, const model::create_volume_request &req);

	pair<string,long> delete_volume(utils::http_var &info, const model::delete_volume_request &req);

	pair<string,long> show_delete_on_termination_flag(utils::http_var &info, const model::show_delete_on_termination_flag_request &req);

	pair<string,long> update_delete_on_termination_flag(utils::http_var &info, const model::update_delete_on_termination_flag_request &req);
}
#endif VOLUME_DEFINER_H
