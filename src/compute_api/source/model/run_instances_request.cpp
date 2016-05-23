#include <vector>
#include <string>
#include "../../../utils.cpp"

using namespace std;
using namespace utils;

class run_instances_request
{
private:
	string image_id;
	string instances_type_id;
	vector<struct utils::block_device_mapping> blocks;
	int instance_count;
	string subnet_id;
	string private_ip_address;
	vector<string> security_group_ids;
	string key_name;

public:

	run_instances_request()
	{
		image_id = "";
		instance_type_id = "";
		blocks = vector<struct utils::block_device_mapping>();
		instance_count = -1;
		subnet_id = "";
		private_ip_adddress = "";
		security_group_ids = vector<string>();
		key_name = "";
	}

	string get_image_id()
	{
		return get_image_id;
	}

	void set_image_id(string image_id_)
	{
		image_id = image_id_;		
	}

	string get_instance_type_id()
	{
		return instance_type_id;
	}

	void set_instance_type_id(string instance_type_id_)
	{
		instance_type_id = instance_type_id_;
	}

	vector<struct utils::block_device_mapping> get_block_device_mapping()
	{
		return blocks;
	}

	void set_block_device_maping(vector <struct utils::block_device_mapping> block_set)
	{
		for(int i=0 ; i<block_set.size() ; i++)
		{
			blocks.push_back(block_set[i]);
		}

	}

	int get_instance_count()
	{
		return instance_count;
	}

	void set_instance_count(int instance_count_)
	{
		instance_count = instance_count_;
	}

	string get_subnet_id()
	{
		return subnet_id;
	}

	void set_subnet_id(string subnet_id_)
	{
		subnet_id = subnet_id_;
	}

	string get_private_ip_address()
	{
		return private_ip_address;
	}

	void set_private_ip_adddress(string private_ip_adddress_)
	{
		private_ip_address = private_ip_adddress_;
	}

	vector<string> get_security_group_id()
	{
		return security_group_ids;
	}

	void set_security_group_id(vector<string> security_group_id_set)
	{
		for(int i=0 ; i<security_group_id_set.size() ; i++)
		{
			security_group_ids.push_back(security_group_id_set[i]);
		}

	}

	string get_key_name()
	{
		return key_name;
	}

	void set_key_name(string kay_name_)
	{
		key_name = key_name_;
	}
};