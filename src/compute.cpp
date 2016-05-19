#include "requestify.cpp"
#include "compute_api/image.cpp"
#include "compute_api/instance.cpp"
#include "compute_api/volume.cpp"
#include "compute_api/snapshot.cpp"
#include "compute_api/key_pair.cpp"
#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;

class compute{
	http_var info;
public:
	compute()
	{
		strcpy(info.url, get_service_url("compute").c_str());
		strcpy(info.verb, "GET");
		strcpy(info.headers, "");
		strcpy(info.version, "2016-03-01");
	}

	string describe_images(vector<string>image_ids = vector<string>())
	{
		string result;
		result = ::describe_images(info, image_ids);
		return result;
	}

	string describe_instances(vector<string>instance_ids = vector<string>())
	{
		string result;
		result = ::describe_instances(info,instance_ids);
		return result;
	}

	string describe_instance_types(vector<string>instance_type_ids = vector<string>())
	{
		string result;
		result = ::describe_instance_types(info,instance_type_ids);
		return result;
	}

	string start_instances(vector<string> instance_ids)
	{
		string result;
		result = ::start_instances(info,instance_ids);
		return result;
	}

	string stop_instances(vector<string> instance_ids)
	{
		string result;
		result = ::stop_instances(info,instance_ids);
		return result;
	}

	string reboot_instances(vector<string> instance_ids)
	{
		string result;
		result = ::reboot_instances(info,instance_ids);
		return result;
	}

	string terminate_instances(vector<string> instance_ids)
	{
		string result;
		result = ::terminate_instances(info,instance_ids);
		return result;
	}

	//edit.. block device mapping
	string run_instances(string image_id, string instance_type_id, 
						vector<struct block_device_mapping> blocks = vector<struct block_device_mapping>(),
 						int instance_count = 1, string subnet_id = "", string private_ip_address = "",
 						vector<string> security_group_ids = vector<string>(), string key_name = "" )
	{
		string result;
		result = ::run_instances(info, image_id, instance_type_id, blocks, instance_count, subnet_id, private_ip_address, security_group_ids, key_name);
		return result;		
	}

	string describe_key_pairs()
	{
		string result;
		result = ::describe_key_pairs(info);
		return result;		
	}

	string create_key_pair(string key_name)
	{
		string result;
		result = ::create_key_pair(info,key_name);
		return result;		
	}

	string delete_key_pair(string key_name)
	{
		string result;
		result = ::delete_key_pair(info,key_name);
		return result;		
	}

	string import_key_pair(string key_name, string public_key_material)
	{
		string result;
		result = ::import_key_pair(info,key_name,public_key_material);
		return result;		
	}

	string delete_snapshot(string snapshot_id)
	{
		string result;
		result = ::delete_snapshot(info,snapshot_id);
		return result;		
	}

	string create_snapshot(string volume_id)
	{
		string result;
		result = ::create_snapshot(info,volume_id);
		return result;		
	}

	string describe_snapshots(vector<string> snapshot_ids  = vector<string>(),
 				 int max_results = -1, string next_token = "", bool detail = true)
	{
		string result;
		result = ::describe_snapshots(info, snapshot_ids, max_results, next_token, detail);
		return result;		
	}

	string create_volume(int size  = -1, string snapshot_id = "")
	{
		string result;
		result = ::create_volume(info, size, snapshot_id);
		return result;		
	}

	string delete_volume(string volume_id)
	{
		string result;
		result = ::delete_volume(info,volume_id);
		return result;		
	}

	string detach_volume(string instance_id, string volume_id)
	{
		string result;
		result = ::detach_volume(info, instance_id, volume_id);
		return result;		
	}

	string attach_volume(string instance_id, string volume_id, string device)
	{
		string result;
		cout<<instance_id<<" "<<volume_id <<" "<<device<<endl;
		result = ::attach_volume(info, instance_id, volume_id, device);
		return result;
	}

	string describe_volumes(vector<string> volume_ids  = vector<string>(),
 					 int max_results = -1, string next_token = "", bool detail = true)
	{
		string result;
		result = ::describe_volumes(info, volume_ids, max_results, next_token, detail);
		return result;
	}

	string show_delete_on_termination_flag(string volume_id )
	{
		string result;
		result = ::show_delete_on_termination_flag(info, volume_id);
		return result;
	}

	string update_delete_on_termination_flag(string volume_id, bool delete_on_termination )
	{
		string result;
		result = ::update_delete_on_termination_flag(info, volume_id, delete_on_termination);
		return result;
	}

};

int main(){
	compute obj;
	string result;
	string instance_id;
	vector<string>image_ids;
	// image_ids.push_back("i-ec554304");
	// image_ids.push_back("i-cbf85c81");
	// result = obj.attach_volume("i-cbf85c81","6444474e-8d07-4d39-aa38-11f2dfca9959", "/dev/vdb");
	// result = obj.describe_volumes();
	result = obj.show_delete_on_termination_flag("6444474e-8d07-4d39-aa38-11f2dfca9959");
	cout<<result<<endl;
	return 0;
}