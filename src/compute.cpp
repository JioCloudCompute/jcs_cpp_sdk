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

#include "src/compute.hpp"
using namespace JIOCOMPUTE;

compute::compute(){
			strcpy(info.url,(config::get_service_url("compute")).c_str());
			strcpy(info.verb, "GET");
			strcpy(info.headers, "");
			strcpy(info.version, "2016-03-01");
		}

describe_images_response *compute::describe_images(const describe_images_request &req)
	{
		pair<string, long> response = image::describe_images(info, req);
		if(response.second == 200)
		{ 
			describe_images_response *res = new describe_images_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}

	}

describe_instances_response *compute::describe_instances(const describe_instances_request &req)
	{
		pair<string, long> response = instance::describe_instances(info, req);
		if(response.second == 200)
		{ 
			describe_instances_response *res = new describe_instances_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}

describe_instance_types_response *compute::describe_instance_types(const describe_instance_types_request &req)
	{
		pair<string, long> response = instance::describe_instance_types(info, req);
		if(response.second == 200)
		{ 
			describe_instance_types_response *res = new describe_instance_types_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
start_instances_response *compute::start_instances(const start_instances_request &req)
	{
		pair<string, long> response = instance::start_instances(info, req);
		if(response.second == 200)
		{ 
			start_instances_response *res = new start_instances_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
stop_instances_response *compute::stop_instances(const stop_instances_request &req)
	{
		pair<string, long> response = instance::stop_instances(info, req);
		if(response.second == 200)
		{ 
			stop_instances_response *res = new stop_instances_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
reboot_instances_response *compute::reboot_instances(const reboot_instances_request &req)
	{
		pair<string, long> response = instance::reboot_instances(info, req);
		if(response.second == 200)
		{ 
			reboot_instances_response *res = new reboot_instances_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
terminate_instances_response *compute::terminate_instances(const terminate_instances_request &req)
	{
		pair<string, long> response = instance::terminate_instances(info, req);
		if(response.second == 200)
		{ 
			terminate_instances_response *res = new terminate_instances_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
run_instances_response *compute::run_instances(const run_instances_request &req)
	{
		pair<string, long> response = instance::run_instances(info, req);
		if(response.second == 200)
		{ 
			run_instances_response *res = new run_instances_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
describe_key_pairs_response *compute::describe_key_pairs()
	{
		pair<string, long> response = key_pair::describe_key_pairs(info);
		if(response.second == 200)
		{ 
			describe_key_pairs_response *res = new describe_key_pairs_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
create_key_pair_response *compute::create_key_pair(const create_key_pair_request &req)
	{
		pair<string, long> response = key_pair::create_key_pair(info, req);
		if(response.second == 200)
		{ 
			create_key_pair_response *res = new create_key_pair_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
delete_key_pair_response *compute::delete_key_pair(const delete_key_pair_request &req)
	{
		pair<string, long> response = key_pair::delete_key_pair(info, req);
		if(response.second == 200)
		{ 
			delete_key_pair_response *res = new delete_key_pair_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
import_key_pair_response *compute::import_key_pair(const import_key_pair_request &req)
	{
		pair<string, long> response = key_pair::import_key_pair(info, req);
		if(response.second == 200)
		{ 
			import_key_pair_response *res = new import_key_pair_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
describe_snapshots_response *compute::describe_snapshots(const describe_snapshots_request &req)
	{
		pair<string, long> response = snapshot::describe_snapshots(info, req);
		if(response.second == 200)
		{ 
			describe_snapshots_response *res = new describe_snapshots_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
create_snapshot_response *compute::create_snapshot(const create_snapshot_request &req)
	{
		pair<string, long> response = snapshot::create_snapshot(info, req);
		if(response.second == 200)
		{ 
			create_snapshot_response *res = new create_snapshot_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
delete_snapshot_response *compute::delete_snapshot(const delete_snapshot_request &req)
	{
		pair<string, long> response = snapshot::delete_snapshot(info, req);
		if(response.second == 200)
		{ 
			delete_snapshot_response *res = new delete_snapshot_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
describe_volumes_response *compute::describe_volumes(const describe_volumes_request &req)
	{
		pair<string, long> response = volume::describe_volumes(info, req);
		if(response.second == 200)
		{ 
			describe_volumes_response *res = new describe_volumes_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
create_volume_response *compute::create_volume(const create_volume_request &req)
	{
		pair<string, long> response = volume::create_volume(info, req);
		if(response.second == 200)
		{ 
			create_volume_response *res = new create_volume_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
delete_volume_response *compute::delete_volume(const delete_volume_request &req)
	{
		pair<string, long> response = volume::delete_volume(info, req);
		if(response.second == 200)
		{ 
			delete_volume_response *res = new delete_volume_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
attach_volume_response *compute::attach_volume(const attach_volume_request &req)
	{
		pair<string, long> response = volume::attach_volume(info, req);
		if(response.second == 200)
		{ 
			attach_volume_response *res = new attach_volume_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
detach_volume_response *compute::detach_volume(const detach_volume_request &req)
	{
		pair<string, long> response = volume::detach_volume(info, req);
		if(response.second == 200)
		{ 
			detach_volume_response *res = new detach_volume_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
show_delete_on_termination_flag_response *compute::show_delete_on_termination_flag(const show_delete_on_termination_flag_request &req)
	{
		pair<string, long> response = volume::show_delete_on_termination_flag(info, req);
		if(response.second == 200)
		{ 
			show_delete_on_termination_flag_response *res = new show_delete_on_termination_flag_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
update_delete_on_termination_flag_response *compute::update_delete_on_termination_flag(const update_delete_on_termination_flag_request &req)
	{
		pair<string, long> response = volume::update_delete_on_termination_flag(info, req);
		if(response.second == 200)
		{ 
			update_delete_on_termination_flag_response *res = new update_delete_on_termination_flag_response(response.first);
			return res;
		}
		else
		{	
			error_report_parse(response.first);
			return NULL;
		}
	}
get_password_data_response *compute::get_password_data(const get_password_data_request &req)
	{
		pair<string , long > response = instance::get_password_data(info,req);
		if(response.second == 200)
		{
			get_password_data_response *res = new get_password_data_response(response.first);
			
			if(res!=NULL)
			{
				res->set_data(instance::decrypt_password((res->get_password_data()).c_str(), req.get_private_key_file(), req.get_passphrase()));

			}

			return res;
		}
		else
		{
			error_report_parse(response.first);
			return NULL;
		}
	}

