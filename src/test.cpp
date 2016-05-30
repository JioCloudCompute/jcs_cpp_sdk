#include "compute.cpp"
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
				instance_ids.push_back("i-54dbd6a2");
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
				instance_ids.push_back("i-54dbd6a2");
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
				instance_ids.push_back("i-54dbd6a2");
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
				instance_ids.push_back("i-54dbd6a2");
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
				req9.set_key_name("cpp_test3");
				res9 = obj.create_key_pair(req9);
				if(res9!=NULL){
					cout<<res9->get_key_material()<<endl;
					cout<<res9->get_key_fingerprint()<<endl;
					cout<<res9->get_key_name()<<endl	;
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
				req11.set_volume_id("7ed67cb4-0ce6-45d9-9a07-4a0ae168912a");
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
				req12.set_snapshot_id("54790b1f-0d24-4375-9d33-1437036ef877");
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
				// req14.set_snapshot_id("54790b1f-0d24-4375-9d33-1437036ef877");
				req14.set_size(6);
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
				req15.set_volume_id("24721771-d20b-4e31-8b8e-cdcf873017fe");
				res15 = obj.delete_volume(req15);
				if(res15!=NULL){
					cout<<res15->get_result()<<endl;
				}
				delete res15;
				break;
			}
			case 16:
			{	//attach volume
				attach_volume_request req16;
				attach_volume_response *res16;
				req16.set_volume_id("24721771-d20b-4e31-8b8e-cdcf873017fe");
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
				req17.set_volume_id("24721771-d20b-4e31-8b8e-cdcf873017fe");
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
				req19.set_volume_id("24721771-d20b-4e31-8b8e-cdcf873017fe");
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
				req20.set_volume_id("24721771-d20b-4e31-8b8e-cdcf873017fe");
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
		instance_ids.clear();
	}
	return 0;
}
