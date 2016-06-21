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
#ifndef INSTANCE_DEFINER_H
#define INSTANCE_DEFINER_H
#include <iostream>
#include <string>
#include "src/compute_api/include/model/describe_instances_response.hpp"
#include "src/compute_api/include/model/describe_instances_request.hpp"
#include "src/compute_api/include/model/run_instances_response.hpp"
#include "src/compute_api/include/model/run_instances_request.hpp"
#include "src/compute_api/include/model/start_instances_response.hpp"
#include "src/compute_api/include/model/start_instances_request.hpp"
#include "src/compute_api/include/model/stop_instances_response.hpp"
#include "src/compute_api/include/model/stop_instances_request.hpp"
#include "src/compute_api/include/model/terminate_instances_response.hpp"
#include "src/compute_api/include/model/terminate_instances_request.hpp"
#include "src/compute_api/include/model/reboot_instances_response.hpp"
#include "src/compute_api/include/model/reboot_instances_request.hpp"
#include "src/compute_api/include/model/describe_instance_types_response.hpp"
#include "src/compute_api/include/model/describe_instance_types_request.hpp"
#include "src/compute_api/include/model/get_password_data_request.hpp"
#include "src/compute_api/include/model/get_password_data_response.hpp"
#include "src/utils.hpp"


using namespace std;

namespace instance
{
	pair<string,long> describe_instances(utils::http_var &info, const model::describe_instances_request &req);
	
	pair<string,long> describe_instance_types(utils::http_var &info, const model::describe_instance_types_request &req);
	
	pair<string,long> start_instances(utils::http_var &info, const model::start_instances_request &req);
	
	pair<string,long> stop_instances(utils::http_var &info, const model::stop_instances_request &req);
	
	pair<string,long> reboot_instances(utils::http_var &info, const model::reboot_instances_request &req);

	pair<string,long> terminate_instances(utils::http_var &info, const model::terminate_instances_request &req);

	pair<string,long> run_instances(utils::http_var &info, const model::run_instances_request &req );

	pair<string, long> get_password_data(utils::http_var &info, const model::get_password_data_request &req);
	
	string decrypt_password(const char* encrypted_password, const std::string &private_key_file, const std::string passphrase);

}
#endif