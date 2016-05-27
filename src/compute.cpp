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
	compute()
	{
		//separate compute from config
		strcpy(info.url, config::get_service_url("compute").c_str());
		strcpy(info.verb, "GET");
		strcpy(info.headers, "");
		strcpy(info.version, "2016-03-01");

	}

	describe_images_response *describe_images(describe_images_request &req)
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

	describe_instances_response *describe_instances(describe_instances_request &req)
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

	describe_instance_types_response *describe_instance_types(describe_instance_types_request &req)
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
	start_instances_response *start_instances(start_instances_request &req)
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
	stop_instances_response *stop_instances(stop_instances_request &req)
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
	reboot_instances_response *reboot_instances(reboot_instances_request &req)
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
	terminate_instances_response *terminate_instances(terminate_instances_request &req)
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
	run_instances_response *run_instances(run_instances_request &req)
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
	create_key_pair_response *create_key_pair(create_key_pair_request &req)
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
	delete_key_pair_response *delete_key_pair(delete_key_pair_request &req)
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
	import_key_pair_response *import_key_pair(import_key_pair_request &req)
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
	describe_snapshots_response *describe_snapshots(describe_snapshots_request &req)
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
	create_snapshot_response *create_snapshot(create_snapshot_request &req)
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
	delete_snapshot_response *delete_snapshot(delete_snapshot_request &req)
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
	describe_volumes_response *describe_volumes(describe_volumes_request &req)
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
	create_volume_response *create_volume(create_volume_request &req)
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
	delete_volume_response *delete_volume(delete_volume_request &req)
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
	attach_volume_response *attach_volume(attach_volume_request &req)
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
	detach_volume_response *detach_volume(detach_volume_request &req)
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
	show_delete_on_termination_flag_response *show_delete_on_termination_flag(show_delete_on_termination_flag_request &req)
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
	update_delete_on_termination_flag_response *update_delete_on_termination_flag(update_delete_on_termination_flag_request &req)
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

int main()
{
	compute obj;
	vector<string>instance_ids;
	int option;
	cin>>option;
	while(option!=-1)
	{
		
		switch(option)
		{
			case 0:
			{
				//describe Images
				describe_images_request req0;
				describe_images_response *res0;
				res0 = obj.describe_images(req0);
				if(res0 != NULL)cout << res0->get_images()[0].get_image_id();
				delete res0;
				break;
			}
			case 1:
			{
				//describe Instance 
				describe_instances_request req1;
				describe_instances_response *res1;
				// vector<string> v;
				// v.push_back("sdc");
				// req1.set_instance_ids(v);
				res1 = obj.describe_instances(req1);
				if(res1!=NULL){
					vector<model::instance> tr = res1->get_instances();
					for(int i = 0;i<tr.size();i++)
					{
						cout<<tr[i].get_instance_id()<<endl;
						cout<<tr[i].get_instance_state()<<endl;
						cout<<endl;
					}
				}
				delete res1;
				break;
			}
			case 2:
			{
				//describe instance types
				describe_instance_types_request req2;
				describe_instance_types_response *res2;
				res2 = obj.describe_instance_types(req2);
				if(res2!=NULL){
					vector<model::instance_type> tr = res2->get_instance_types();
					for(int i=0 ; i<tr.size() ; i++)cout<<tr[i].get_ram	()<<endl;
				}
				delete res2;
				break;
			}
			case 3:
			{
				// Stop instances
				stop_instances_request req3;
				stop_instances_response *res3;
				instance_ids.push_back("i-5f238d8d");
				req3.set_instance_ids(instance_ids);
				res3 = obj.stop_instances(req3);
				if(res3!=NULL){
					vector<model::instance_set> tr = res3->get_instances();

					for(int i=0 ; i<tr.size() ; i++)
					{
						cout<<tr[i].get_instance_id()<<endl;
						cout<<tr[i].get_current_state()<<endl;
						cout<<endl;
					}
				}
				delete res3;
				break;
			}
			case 4:	
			{	//start Instances
				start_instances_request req4;
				start_instances_response *res4;
				instance_ids.push_back("i-b825503d");
				instance_ids.push_back("i-a1e14a93");
				req4.set_instance_ids(instance_ids);
				res4 = obj.start_instances(req4);
				if(res4!=NULL){	
					vector< model::instance_set> tr = res4->get_instances();

					for(int i =0;i<tr.size();i++)
					{
						cout<<tr[i].get_instance_id()<<endl;
						cout<<tr[i].get_current_state()<<endl;
						cout<<endl;
					}
				}
				delete res4;
				break;
			}
			case 5:
			{
				//Reboot Instances
				reboot_instances_request req5;
				reboot_instances_response *res5;
				instance_ids.push_back("i-b825503d");
				instance_ids.push_back("i-a1e14a93");
				req5.set_instance_ids(instance_ids);
				res5 = obj.reboot_instances(req5);
				if(res5!=NULL){
					vector< model::instance_set> tr = res5->get_instances();
					for(int i =0;i<tr.size();i++)
					{
						cout<<tr[i].get_instance_id()<<endl;
						cout<<tr[i].get_current_state()<<endl;
						cout<<endl;
					}
				}
				delete res5;
				break;
			}
			case 6:
			{
				//terminate Instances
				terminate_instances_request req6;
				terminate_instances_response *res6;
				instance_ids.push_back("i-b825503d");
				instance_ids.push_back("i-a1e14a93");
				req6.set_instance_ids(instance_ids);
				res6 = obj.terminate_instances(req6);
				if(res6!=NULL){
					vector< model::instance_set> tr = res6->get_instances();
					for(int i =0;i<tr.size();i++)
					{
						cout<<tr[i].get_instance_id()<<endl;
						cout<<tr[i].get_current_state()<<endl;
						cout<<endl;
					}
				}
				delete res6;
				break;
			}		
			case 7:
			{
				// Run Instances
				run_instances_request req7;
				run_instances_response *res7;
				req7.set_image_id("jmi-bc345d58");
				req7.set_instance_type_id("c1.large");
				res7 = obj.run_instances(req7);
				if(res7!=NULL){
					vector< model::instance> tr = res7->get_instances();

					for(int i =0;i<tr.size();i++)
					{
						cout<<tr[i].get_instance_id()<<endl;	
						cout<<tr[i].get_instance_state()<<endl;
					}
				}
				delete res7;
				break;
			}
			case 8:
			{
				//describe key pairs 
				describe_key_pairs_response *res8;
				res8 = obj.describe_key_pairs();
				if(res8!=NULL){
					vector<model::key_pair> tr = res8->get_key_pairs();
					for(int i=0 ; i<tr.size() ; i++)
					{
						cout<<tr[i].get_key_name()<<endl;	
					}
				}
				delete res8;
				break;
			}
			case 9:
			{
				//create key pair 
				create_key_pair_request req9;
				create_key_pair_response *res9;
				req9.set_key_name("cpp_test4");
				res9 = obj.create_key_pair(req9);
				if(res9!=NULL){
					cout<<res9->get_key_material()<<endl;
					cout<<res9->get_key_fingerprint()<<endl;
					cout<<res9->get_key_name()<<endl;
				}
				delete res9;
				break;
			}
			case 10:
			{
				// Delete key pair
				delete_key_pair_request req10;
				delete_key_pair_response *res10;
				req10.set_key_name("cpp_test3");
				res10 = obj.delete_key_pair(req10);
				if(res10!=NULL){
					cout<<res10->get_result()<<endl;
				}
				delete res10;
				break;
			}
			case 11:
			{
				// create snapshot
				create_snapshot_request req11;
				create_snapshot_response *res11;
				req11.set_volume_id("c62c289e-e9a8-4251-bb47-85305352904a");
				res11 = obj.create_snapshot(req11);
				if(res11!=NULL){
					cout<<res11->get_status()<<endl;
					cout<<res11->get_snapshot_id()<<endl;
					cout<<res11->get_volume_size()<<endl;
					cout<<res11->get_volume_id()<<endl;
				}
				delete res11;
				break;
			}
			case 12:
			{
				//Delete snapshot
				delete_snapshot_request req12;
				delete_snapshot_response *res12;
				req12.set_snapshot_id("755bea03-ecde-46d3-b92e-6e4eb9367254");
				res12 = obj.delete_snapshot(req12);
				if(res12!=NULL){
					cout<<res12->get_result()<<endl;
				}
				delete res12;
				break;
			}
			case 13:
			{
				//describe snapshots 
				describe_snapshots_request req13;
				describe_snapshots_response *res13;
				res13 = obj.describe_snapshots(req13);
				if(res13!=NULL){
					vector<model::snapshot> tr = res13->get_snapshot_set();
					for(int i=0 ; i<tr.size() ; i++)
					{
						cout<<tr[i].get_snapshot_id()<<endl;
						cout<<tr[i].get_volume_id()<<endl;
						cout<<tr[i].get_volume_size()<<endl;
					}
				}
				delete res13;
				break;
			}
			case 14:
			{	// Create volume
				create_volume_request req14;
				create_volume_response *res14;
				req14.set_snapshot_id("54790b1f-0d24-4375-9d33-1437036ef877");
				res14 = obj.create_volume(req14);
				if(res14!=NULL){
					cout<<res14->get_status()<<endl;
					cout<<res14->get_volume_id()<<endl;
					cout<<res14->get_snapshot_id()<<endl;
				}
				delete res14;
				break;
			}
			case 15:
			{	// delete volume
				delete_volume_request req15;
				delete_volume_response *res15;
				req15.set_volume_id("69ab9944-64f5-467d-b3f9-fccd3b5d593d");
				res15 = obj.delete_volume(req15);
				if(res15!=NULL){
					cout<<res15->get_status()<<endl;
				}
				delete res15;
				break;
			}
			case 16:
			{	//attach volume
				attach_volume_request req16;
				attach_volume_response *res16;
				req16.set_volume_id("3e6b832f-755f-42eb-b346-d209628a6ce7");
				req16.set_instance_id("i-407bb8fb");
				req16.set_device("/dev/vdb");
				res16 = obj.attach_volume(req16);
				if(res16!=NULL){
					cout<<res16->get_status()<<endl;
				}
				delete res16;
				break;
			}
			case 17:
			{
				//detach volume
				detach_volume_request req17;
				detach_volume_response *res17;
				req17.set_volume_id("3e6b832f-755f-42eb-b346-d209628a6ce7");
				res17 = obj.detach_volume(req17);
				if(res17!=NULL){
					cout<<res17->get_status()<<endl;
				}
				delete res17;
				break;
			}
			case 18:
			{
				// Describe volumes
				describe_volumes_request req18;
				describe_volumes_response *res18;
				res18 = obj.describe_volumes(req18);
				if(res18!=NULL){
					vector<model::volume> tr = res18->get_volume_set();
					for(int i=0 ; i<tr.size() ; i++)
					{
						cout<<tr[i].get_volume_id()<<endl;
						cout<<tr[i].get_status()<<endl;
						cout<<tr[i].get_size()<<endl;
						cout<<tr[i].get_instance_id()<<endl;
					}
				}
				delete res18;
				break;
			}
			case 19:
			{	// show delete on termination flag
				show_delete_on_termination_flag_request req19;
				show_delete_on_termination_flag_response *res19;
				req19.set_volume_id("421d256b-541f-4baa-940e-2c023804b0a6");
				res19 = obj.show_delete_on_termination_flag(req19);
				if(res19!=NULL){
					cout<<res19->get_volume_id()<<endl;
					cout<<res19->get_delete_on_termination()<<endl;
				}
				delete res19;
				break;
			}
			case 20:
			{
				// update delete on termination flag
				update_delete_on_termination_flag_request req20;
				update_delete_on_termination_flag_response *res20;
				req20.set_volume_id("421d256b-541f-4baa-940e-2c023804b0a6");
				req20.set_delete_on_termination(1);
				res20 = obj.update_delete_on_termination_flag(req20);
				if(res20!=NULL){
					cout<<res20->get_volume_id()<<endl;
					cout<<res20->get_delete_on_termination()<<endl;
				}
				delete res20;
				break;
			}
			default:
				break;
		}
		cin>>option;
	}
	return 0;
}
