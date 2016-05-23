#include "src/requestify.cpp"
#include "src/compute_api/source/image.cpp"
// #include "src/compute_api/source/instance.cpp"
// #include "src/compute_api/source/volume.cpp"
// #include "src/compute_api/source/snapshot.cpp"
// #include "src/compute_api/source/key_pair.cpp"
#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;
using namespace image;
// using namespace instance;
// using namespace snapshot;
// using namespace key_pair;
// using namespace volume;
using namespace utils;
using namespace config;

class compute{
	utils::http_var info;
public:
	compute()
	{
		//separate compute from config
		strcpy(info.url, config::get_service_url("compute").c_str());
		strcpy(info.verb, "GET");
		strcpy(info.headers, "");
		strcpy(info.version, "2016-03-01");
	}

	//Use C++ structures and class instead of string for result
	describe_images_response describe_images(describe_images_request &req)
	{
		return describe_images_response(image::describe_images(info, req));
	}

	// string describe_instances(vector<string>instance_ids = vector<string>())
	// {
	// 	return instance::describe_instances(info,instance_ids);
	// }

	// string describe_instance_types(vector<string>instance_type_ids = vector<string>())
	// {
	// 	return instance::describe_instance_types(info,instance_type_ids);
	// }

	// string start_instances(const vector<string> & instance_ids)
	// {
	// 	return instance::start_instances(info,instance_ids);
	// }

	// string stop_instances(vector<string> instance_ids)
	// {
	// 	return instance::stop_instances(info,instance_ids);
	// }

	// string reboot_instances(vector<string> instance_ids)
	// {
	// 	return instance::reboot_instances(info,instance_ids);
	// }

	// string terminate_instances(vector<string> instance_ids)
	// {
	// 	return instance::terminate_instances(info,instance_ids);
	// }

	// //edit.. block device mapping
	// string run_instances(string image_id, string instance_type_id, 
	// 					vector<struct utils::block_device_mapping> blocks = vector<struct utils::block_device_mapping>(),
 // 						int instance_count = 1, string subnet_id = "", string private_ip_address = "",
 // 						vector<string> security_group_ids = vector<string>(), string key_name = "" )
	// {
	// 	return instance::run_instances(info, image_id, instance_type_id, blocks, instance_count, subnet_id, private_ip_address, security_group_ids, key_name);
	// }

	// string describe_key_pairs()
	// {
	// 	return key_pair::describe_key_pairs(info);
	// }

	// string create_key_pair(string key_name)
	// {
	// 	return key_pair::create_key_pair(info,key_name);
	// }

	// string delete_key_pair(string key_name)
	// {
	// 	return key_pair::delete_key_pair(info,key_name);
	// }

	// string import_key_pair(string key_name, string public_key_material)
	// {
	// 	return key_pair::import_key_pair(info,key_name,public_key_material);
	// }

	// string delete_snapshot(string snapshot_id)
	// {
	// 	return snapshot::delete_snapshot(info,snapshot_id);
	// }

	// string create_snapshot(string volume_id)
	// {
	// 	return snapshot::create_snapshot(info,volume_id);
	// }

	// string describe_snapshots(vector<string> snapshot_ids  = vector<string>(),
 // 				 int max_results = -1, string next_token = "", bool detail = true)
	// {
	// 	return snapshot::describe_snapshots(info, snapshot_ids, max_results, next_token, detail);
	// }

	// string create_volume(int size  = -1, string snapshot_id = "")
	// {
	// 	return volume::create_volume(info, size, snapshot_id);
	// }

	// string delete_volume(string volume_id)
	// {
	// 	return volume::delete_volume(info,volume_id);
	// }

	// string detach_volume(string instance_id, string volume_id)
	// {
	// 	return volume::detach_volume(info, instance_id, volume_id);
	// }

	// string attach_volume(string instance_id, string volume_id, string device)
	// {
	// 	return volume::attach_volume(info, instance_id, volume_id, device);
	// }

	// string describe_volumes(vector<string> volume_ids  = vector<string>(),
 // 					 int max_results = -1, string next_token = "", bool detail = true)
	// {
	// 	return volume::describe_volumes(info, volume_ids, max_results, next_token, detail);
	// }

	// string show_delete_on_termination_flag(string volume_id )
	// {
	// 	return volume::show_delete_on_termination_flag(info, volume_id);
	// }

	// string update_delete_on_termination_flag(string volume_id, bool delete_on_termination )
	// {
	// 	return volume::update_delete_on_termination_flag(info, volume_id, delete_on_termination);
	// }

};

int main(){
	compute obj;
	// string result;
	// string instance_id;
	// vector<string>image_ids;
	describe_images_request req;
	describe_images_response res;
	res = obj.describe_images(req);
	// image_ids.push_back("i-ec554304");
	// image_ids.push_back("i-cbf85c81");
	// return obj.attach_volume("i-cbf85c81","6444474e-8d07-4d39-aa38-11f2dfca9959", "/dev/vdb");
	// result = obj.describe_instance_types();
	//return obj.show_delete_on_termination_flag("6444474e-8d07-4d39-aa38-11f2dfca9959");
	// cout<<result<<endl;
	cout<<res.Images["jmi-e3ba830a"].name;
	return 0;
}
