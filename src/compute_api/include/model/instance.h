#ifndef INSTANCE_H
#define INSTANCE_H
#include <vector>
#include <string>
#include <map>
#include "block_device_instance.h"

using namespace std;
namespace model
{
	class group_set
	{
	public:
		string group_name;
		string group_id;
	};

	class instance{
	private:
		
		vector<block_device_instance> block_devices;
		string dns_name;
		string instance_id;
		string instance_state;  //STATE definition
		string image_id;
		string private_dns_name;
		string key_name;

		string launch_time;
		string subnet_id;
		vector< group_set > group;
		string vpc_id;
		string instance_type;
		string private_ip_address;
	public:
		instance(){}


		// Constructor used by describe_instances_response
		instance(vector<block_device_instance> block_devices_, string dns_name_ , string instance_id_, string instance_state_, string image_id_, string private_dns_name_, string key_name_,
				string launch_time_, string subnet_id_, vector<group_set>group_ ,string vpc_id_, string instance_type_, string private_ip_address_)
		{
			block_devices = block_devices_;
			dns_name = dns_name_;
			instance_id = instance_id_;
			instance_state = instance_state_;
			image_id = image_id_;
			private_dns_name_ = private_dns_name_;
			key_name = key_name_;
			launch_time = launch_time_;
			subnet_id = subnet_id_;
			group = group_;
			vpc_id = vpc_id_;
			instance_type = instance_type_;
			private_ip_address = private_ip_address_;
		}

		// Constructor used by run_instances_response
		instance(string vpc_id_, string dns_name_ , string instance_id_, string instance_state_, string image_id_, string private_dns_name_, string key_name_,
				string launch_time_, string subnet_id_, vector<group_set>group_ , string instance_type_, string private_ip_address_)
		{
			dns_name = dns_name_;
			instance_id = instance_id_;
			instance_state = instance_state_;
			image_id = image_id_;
			private_dns_name_ = private_dns_name_;
			key_name = key_name_;
			launch_time = launch_time_;
			subnet_id = subnet_id_;
			group = group_;
			vpc_id = vpc_id_;
			instance_type = instance_type_;
			private_ip_address = private_ip_address_;
		}



		
		const string get_dns_name()
		{
			return dns_name;
		}
		const string get_instance_id()
		{
			return instance_id;
		}
		const string get_instance_state()
		{
			return instance_state;
		}
		const string get_image_id()
		{
			return image_id;
		}

		const string get_private_dns_name()
		{
			return private_dns_name;
		}
		const string get_key_name()
		{
			return key_name;
		}
		const string get_launch_time()
		{
			return launch_time;
		}
		const string get_subnet_id()
		{
			return subnet_id;
		}
		const vector<group_set> get_group()
		{
			return group;
		}
		const string get_vpc_id()
		{
			return vpc_id;
		}
		const string get_instance_type()
		{
			return instance_type;
		}
		const string get_private_ip_address()
		{
			return private_ip_address;
		}
	};
}
#endif

