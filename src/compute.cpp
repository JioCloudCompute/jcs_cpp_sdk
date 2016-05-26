#include "src/requestify.cpp"
#include "src/compute_api/source/image.cpp"
#include "src/compute_api/source/instance.cpp"
#include "src/compute_api/source/volume.cpp"
#include "src/compute_api/source/snapshot.cpp"
#include "src/compute_api/source/key_pair.cpp"
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
		string xmlresponse = image::describe_images(info, req);
		
		return describe_images_response(xmlresponse);
	}

	 describe_instances_response describe_instances(describe_instances_request &req)
	{
		return describe_instances_response(instance::describe_instances(info,req));
	}

	describe_instance_types_response describe_instance_types(describe_instance_types_request &req)
	{
		return describe_instance_types_response(instance::describe_instance_types(info,req));
	}

	start_instances_response start_instances(start_instances_request &req)
	{
		return start_instances_response(instance::start_instances(info,req));
	}
	stop_instances_response stop_instances(stop_instances_request &req)
	{
		return stop_instances_response(instance::stop_instances(info,req));
	}

	reboot_instances_response reboot_instances(reboot_instances_request &req)
	{
		return reboot_instances_response(instance::reboot_instances(info,req));
	}

	terminate_instances_response terminate_instances(terminate_instances_request &req)
	{
		return terminate_instances_response(instance::terminate_instances(info,req));
	}

	// //edit.. block device mapping
	run_instances_response run_instances(run_instances_request &req)
	{
		return run_instances_response(instance::run_instances(info, req));
	}

	describe_key_pairs_response describe_key_pairs()
	{
		return describe_key_pairs_response(key_pair::describe_key_pairs(info));
	}

	create_key_pair_response create_key_pair(create_key_pair_request &req)
	{
		return create_key_pair_response(key_pair::create_key_pair(info,req));
	}

	delete_key_pair_response delete_key_pair(delete_key_pair_request &req)
	{
		return delete_key_pair_response(key_pair::delete_key_pair(info,req));
	}

	import_key_pair_response import_key_pair(import_key_pair_request &req)
	{
		return import_key_pair_response(key_pair::import_key_pair(info,req));
	}

	delete_snapshot_response delete_snapshot(delete_snapshot_request &req)
	{
		return delete_snapshot_response(snapshot::delete_snapshot(info,req));
	}

	create_snapshot_response create_snapshot(create_snapshot_request &req)
	{
		return create_snapshot_response(snapshot::create_snapshot(info,req));
	}

	describe_snapshots_response describe_snapshots(describe_snapshots_request &req)
	{
		return describe_snapshots_response(snapshot::describe_snapshots(info,req));
	}

	create_volume_response create_volume(create_volume_request &req)
	{
		return create_volume_response(volume::create_volume(info, req));
	}

	delete_volume_response delete_volume(delete_volume_request &req)
	{
		return delete_volume_response(volume::delete_volume(info,req));
	}

	detach_volume_response detach_volume(detach_volume_request &req)
	{
		return detach_volume_response(volume::detach_volume(info, req));
	}

	attach_volume_response attach_volume(attach_volume_request &req)
	{
		return attach_volume_response(volume::attach_volume(info, req));
	}

	describe_volumes_response describe_volumes(describe_volumes_request &req)
	{
		return describe_volumes_response (volume::describe_volumes(info,req));
	}

	show_delete_on_termination_flag_response show_delete_on_termination_flag(show_delete_on_termination_flag_request &req )
	{
		return show_delete_on_termination_flag_response(volume::show_delete_on_termination_flag(info, req));
	}

	update_delete_on_termination_flag_response update_delete_on_termination_flag(update_delete_on_termination_flag_request &req)
	{
		return update_delete_on_termination_flag_response(volume::update_delete_on_termination_flag(info, req));
	}

};

int main(){
	compute obj;
	// string result;
	// string instance_id;
	// vector<string>image_ids;
	
	// image_ids.push_back("i-ec554304");
	// image_ids.push_back("i-cbf85c81");
	// return obj.attach_volume("i-cbf85c81","6444474e-8d07-4d39-aa38-11f2dfca9959", "/dev/vdb");
	// result = obj.describe_instance_types();
	//return obj.show_delete_on_termination_flag("6444474e-8d07-4d39-aa38-11f2dfca9959");
	// cout<<result<<endl;

	//describe Instance 
	/*describe_instances_request req;
	describe_instances_response res;
	res = obj.describe_instances(req);
	map<string, model::instance> tr = res.get_instances();
	for(map<string, model::instance>::iterator it = tr.begin();it!=tr.end();it++)cout<<it->second.Get_instanceId()<<endl;
	*/

	//describe instance types
	// describe_instance_types_request req;
	// describe_instance_types_response res;
	// res = obj.describe_instance_types(req);
	// vector<model::instance_type> tr = res.get_instance_types();
	// for(int i=0 ; i<tr.size() ; i++)cout<<tr[i].get_ram	()<<endl;
	
	// Stop instances
	/*stop_instances_request req;
	stop_instances_response res;
	vector<string>instance_ids;
	instance_ids.push_back("i-5f238d8d");
	req.set_instance_ids(instance_ids);
	res = obj.stop_instances(req);
	map<string, model::instance_set> tr = res.get_instances();

	for(map<string, model::instance_set>::iterator it = tr.begin();it!=tr.end();it++)cout<<it->second.get_current_state()<<endl;
*/

	//start Instances
	// start_instances_request req;
	// start_instances_response res;
	// vector<string>instance_ids;
	// instance_ids.push_back("i-b825503d");
	// instance_ids.push_back("i-a1e14a93");
	// req.set_instance_ids(instance_ids);
	// res = obj.start_instances(req);
	// vector< model::instance_set> tr = res.get_instances();

	// for(int i =0;i<tr.size();i++)cout<<tr[i].get_current_state()<<tr[i].get_previous_state()<<endl;	

	//Reboot Instances
	// reboot_instances_request req;
	// reboot_instances_response res;
	// vector<string>instance_ids;
	// instance_ids.push_back("i-b825503d");
	// instance_ids.push_back("i-a1e14a93");
	// req.set_instance_ids(instance_ids);
	// res = obj.reboot_instances(req);
	// vector< model::instance_set> tr = res.get_instances();

	// for(int i =0;i<tr.size();i++)cout<<tr[i].get_current_state()<<tr[i].get_previous_state()<<endl;	


	//terminate Instances
	// terminate_instances_request req;
	// terminate_instances_response res;
	// vector<string>instance_ids;
	// instance_ids.push_back("i-b825503d");
	// instance_ids.push_back("i-a1e14a93");
	// req.set_instance_ids(instance_ids);
	// res = obj.terminate_instances(req);
	// vector< model::instance_set> tr = res.get_instances();

	// for(int i =0;i<tr.size();i++)cout<<tr[i].get_current_state()<<tr[i].get_previous_state()<<endl;	

	// Run Instances
	// run_instances_request req;
	// run_instances_response res;
	// req.set_image_id("jmi-bc345d58");
	// req.set_instance_type_id("c1.large");
	// res = obj.run_instances(req);
	// vector< model::instance> tr = res.get_instances();

	// for(int i =0;i<tr.size();i++)cout<<tr[i].get_instance_id()<<endl;	


	//describe key pairs 
	// describe_key_pairs_request req;
	// describe_key_pairs_response res;
	// res = obj.describe_key_pairs();
	// vector<model::key_pair> tr = res.get_key_pairs();
	// for(int i=0 ; i<tr.size() ; i++)cout<<tr[i].get_key_name()<<endl;	


	//create key pair 
	// create_key_pair_request req;
	// create_key_pair_response res;
	// req.set_key_name("cpp_test4");
	// res = obj.create_key_pair(req);
	// cout<<res.get_key_material()<<endl;
	// cout<<res.get_key_fingerprint()<<endl;
	// cout<<"a"<<res.get_key_material()[31]<<"b";
	// cout<<res.get_key_name()<<endl;

	// Delete key pair
	// delete_key_pair_request req;
	// delete_key_pair_response res;
	// req.set_key_name("cpp_test3");
	// res = obj.delete_key_pair(req);
	// cout<<res.get_result()<<endl;

	// create snapshot
	// create_snapshot_request req;
	// create_snapshot_response res;
	// req.set_volume_id("c62c289e-e9a8-4251-bb47-85305352904a");
	// res = obj.create_snapshot(req);
	// cout<<res.get_status()<<endl;
	// cout<<res.get_snapshot_id()<<endl;
	// cout<<res.get_volume_size()<<endl;
	// cout<<res.get_volume_id()<<endl;
	// cout<<res.get_start_time()<<endl;

	//Delete snapshot
	// delete_snapshot_request req;
	// delete_snapshot_response res;
	// req.set_snapshot_id("755bea03-ecde-46d3-b92e-6e4eb9367254");
	// res = obj.delete_snapshot(req);
	// cout<<res.get_result()<<endl;

	//describe snapshots 
	// describe_snapshots_request req;
	// describe_snapshots_response res;
	// res = obj.describe_snapshots(req);
	// vector<model::snapshot> tr = res.get_snapshot_set();
	// for(int i=0 ; i<tr.size() ; i++){cout<<tr[i].get_snapshot_id()<<endl;cout<<tr[i].get_volume_id()<<endl;cout<<tr[i].get_volume_size()<<endl;}

	// Create volume
	// create_volume_request req;
	// create_volume_response res;
	// req.set_snapshot_id("54790b1f-0d24-4375-9d33-1437036ef877");
	// res = obj.create_volume(req);
	// cout<<res.get_status()<<endl;
	// cout<<res.get_volume_id()<<endl;
	// cout<<res.get_snapshot_id()<<endl;

	// delete volume
	// delete_volume_request req;
	// delete_volume_response res;
	// req.set_volume_id("69ab9944-64f5-467d-b3f9-fccd3b5d593d");
	// res = obj.delete_volume(req);
	// cout<<res.get_status()<<endl;

	//attach volume
	// attach_volume_request req;
	// attach_volume_response res;
	// req.set_volume_id("3e6b832f-755f-42eb-b346-d209628a6ce7");
	// req.set_instance_id("i-407bb8fb");
	// req.set_device("/dev/vdb");
	// res = obj.attach_volume(req);
	// cout<<res.get_status()<<endl;

	//detach volume
	// detach_volume_request req;
	// detach_volume_response res;
	// req.set_volume_id("3e6b832f-755f-42eb-b346-d209628a6ce7");
	// res = obj.detach_volume(req);
	// cout<<res.get_status()<<endl;

	// Describe volumes
	describe_volumes_request req;
	describe_volumes_response res;
	res = obj.describe_volumes(req);
	vector<model::volume> tr = res.get_volume_set();
	for(int i=0 ; i<tr.size() ; i++){cout<<tr[i].get_snapshot_id()<<endl;cout<<tr[i].get_volume_id()<<endl;cout<<tr[i].get_size()<<endl;}

	// show delete on termination flag
	// show_delete_on_termination_flag_request req;
	// show_delete_on_termination_flag_response res;
	// req.set_volume_id("421d256b-541f-4baa-940e-2c023804b0a6");
	// res = obj.show_delete_on_termination_flag(req);
	// cout<<res.get_volume_id()<<endl;
	// cout<<res.get_delete_on_termination()<<endl;


	// update delete on termination flag
	// update_delete_on_termination_flag_request req;
	// update_delete_on_termination_flag_response res;
	// req.set_volume_id("421d256b-541f-4baa-940e-2c023804b0a6");
	// req.set_delete_on_termination(1);
	// res = obj.update_delete_on_termination_flag(req);
	// cout<<res.get_volume_id()<<endl;
	// cout<<res.get_delete_on_termination()<<endl;
	return 0;
}
