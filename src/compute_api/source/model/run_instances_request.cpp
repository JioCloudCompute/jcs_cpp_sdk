#include "src/compute_api/include/model/run_instances_request.h"

using namespace std;
using namespace utils;
using namespace model;

model::run_instances_request::run_instances_request()
{
	instance_count = -1;
}

const string model::run_instances_request::get_image_id() const
{
	return image_id;
}

void model::run_instances_request::set_image_id(const string& image_id_)
{
	image_id = image_id_;		
}

const string model::run_instances_request::get_instance_type_id() const
{
	return instance_type_id;
}

void model::run_instances_request::set_instance_type_id(const string& instance_type_id_)
{
	instance_type_id = instance_type_id_;
}

const vector<struct utils::block_device_mapping> *model::run_instances_request::get_block_device_mapping() const
{
	return &blocks;
}

void model::run_instances_request::set_block_device_maping(const vector <struct utils::block_device_mapping>& block_set)
{
	blocks.insert(blocks.end(), block_set.begin(), block_set.end());
}

const int model::run_instances_request::get_instance_count() const
{
	return instance_count;
}

void model::run_instances_request::set_instance_count(const int &instance_count_)
{
	instance_count = instance_count_;
}

const string model::run_instances_request::get_subnet_id() const
{
	return subnet_id;
}

void model::run_instances_request::set_subnet_id(const string& subnet_id_)
{
	subnet_id = subnet_id_;
}

const string model::run_instances_request::get_private_ip_address() const
{
	return private_ip_address;
}

void model::run_instances_request::set_private_ip_adddress(const string& private_ip_adddress_)
{
	private_ip_address = private_ip_adddress_;
}

const vector<string> *model::run_instances_request::get_security_group_ids() const
{
	return &security_group_ids;
}

void model::run_instances_request::set_security_group_ids(const vector<string>& security_group_id_set)
{
	security_group_ids.insert(security_group_ids.end(), security_group_id_set.begin(), security_group_id_set.end());
}

const string model::run_instances_request::get_key_name() const
{
	return key_name;
}

void model::run_instances_request::set_key_name(const string& key_name_)
{
	key_name = key_name_;
}
