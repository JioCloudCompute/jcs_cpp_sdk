#include "src/requestify.cpp"
#include "src/compute_api/source/image.cpp"
#include "src/compute_api/source/instance.cpp"
#include "src/compute_api/source/volume.cpp"
#include "src/compute_api/source/snapshot.cpp"
#include "src/compute_api/source/key_pair.cpp"
#include "src/compute_api/source/model/error_response.cpp"
#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;
using namespace image;
using namespace instance;
// using namespace snapshot;
// using namespace key_pair;
// using namespace volume;
using namespace utils;
using namespace config;

class compute
{
	utils::http_var info;

public:
		
	compute(){
		strcpy(info.url,(config::get_service_url("compute")).c_str());
		strcpy(info.verb, "GET");
		strcpy(info.headers, "");
		strcpy(info.version, "2016-03-01");
	}


	//make req const
	describe_images_response *describe_images(const describe_images_request &req)
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

	describe_instances_response *describe_instances(const describe_instances_request &req)
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

	describe_instance_types_response *describe_instance_types(const describe_instance_types_request &req)
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
	start_instances_response *start_instances(const start_instances_request &req)
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
	stop_instances_response *stop_instances(const stop_instances_request &req)
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
	reboot_instances_response *reboot_instances(const reboot_instances_request &req)
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
	terminate_instances_response *terminate_instances(const terminate_instances_request &req)
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
	run_instances_response *run_instances(const run_instances_request &req)
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
	describe_key_pairs_response *describe_key_pairs()
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
	create_key_pair_response *create_key_pair(const create_key_pair_request &req)
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
	delete_key_pair_response *delete_key_pair(const delete_key_pair_request &req)
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
	import_key_pair_response *import_key_pair(const import_key_pair_request &req)
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
	describe_snapshots_response *describe_snapshots(const describe_snapshots_request &req)
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
	create_snapshot_response *create_snapshot(const create_snapshot_request &req)
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
	delete_snapshot_response *delete_snapshot(const delete_snapshot_request &req)
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
	describe_volumes_response *describe_volumes(const describe_volumes_request &req)
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
	create_volume_response *create_volume(const create_volume_request &req)
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
	delete_volume_response *delete_volume(const delete_volume_request &req)
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
	attach_volume_response *attach_volume(const attach_volume_request &req)
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
	detach_volume_response *detach_volume(const detach_volume_request &req)
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
	show_delete_on_termination_flag_response *show_delete_on_termination_flag(const show_delete_on_termination_flag_request &req)
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
	update_delete_on_termination_flag_response *update_delete_on_termination_flag(const update_delete_on_termination_flag_request &req)
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
};

