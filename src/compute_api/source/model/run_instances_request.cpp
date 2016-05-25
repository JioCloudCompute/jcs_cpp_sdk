#include "src/compute_api/include/model/run_instances_request.h"

using namespace std;
using namespace utils;
using namespace model;

model::run_instances_request::run_instances_request()
{
	image_id = "";
	instance_type_id = "";
	blocks = vector<struct utils::block_device_mapping>();
	instance_count = -1;
	subnet_id = "";
	private_ip_address = "";
	security_group_ids = vector<string>();
	key_name = "";
}

const string model::run_instances_request::get_image_id()
{
	return image_id;
}

void model::run_instances_request::set_image_id(string image_id_)
{
	image_id = image_id_;		
}

const string model::run_instances_request::get_instance_type_id()
{
	return instance_type_id;
}

void model::run_instances_request::set_instance_type_id(string instance_type_id_)
{
	instance_type_id = instance_type_id_;
}

const vector<struct utils::block_device_mapping> *model::run_instances_request::get_block_device_mapping()
{
	return &blocks;
}

void model::run_instances_request::set_block_device_maping(vector <struct utils::block_device_mapping> block_set)
{
	for(int i=0 ; i<block_set.size() ; i++)
	{
		blocks.push_back(block_set[i]);
	}

}

const int model::run_instances_request::get_instance_count()
{
	return instance_count;
}

void model::run_instances_request::set_instance_count(int instance_count_)
{
	instance_count = instance_count_;
}

const string model::run_instances_request::get_subnet_id()
{
	return subnet_id;
}

void model::run_instances_request::set_subnet_id(string subnet_id_)
{
	subnet_id = subnet_id_;
}

const string model::run_instances_request::get_private_ip_address()
{
	return private_ip_address;
}

void model::run_instances_request::set_private_ip_adddress(string private_ip_adddress_)
{
	private_ip_address = private_ip_adddress_;
}

const vector<string> *model::run_instances_request::get_security_group_id()
{
	return &security_group_ids;
}

void model::run_instances_request::set_security_group_id(vector<string> security_group_id_set)
{
	for(int i=0 ; i<security_group_id_set.size() ; i++)
	{
		security_group_ids.push_back(security_group_id_set[i]);
	}

}

const string model::run_instances_request::get_key_name()
{
	return key_name;
}

void model::run_instances_request::set_key_name(string key_name_)
{
	key_name = key_name_;
}
