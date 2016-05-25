#ifndef RUN_INSTANCES_H
#define RUN_INSTANCES_H
#include <vector>
#include <string>
#include "../../../utils.cpp"

using namespace std;
using namespace utils;
namespace model
{
	class run_instances_request
	{
	private:
		string image_id;
		string instance_type_id;
		vector<struct utils::block_device_mapping> blocks;
		int instance_count;
		string subnet_id;
		string private_ip_address;
		vector<string> security_group_ids;
		string key_name;

	public:
		run_instances_request();
	const string get_image_id();

		void set_image_id(string image_id_);

	const string get_instance_type_id();

		void set_instance_type_id(string instance_type_id_);

	const vector<struct utils::block_device_mapping> *get_block_device_mapping();

		void set_block_device_maping(vector <struct utils::block_device_mapping> block_set);

	const int get_instance_count();

		void set_instance_count(int instance_count_);

	const string get_subnet_id();

		void set_subnet_id(string subnet_id_);

	const string get_private_ip_address();

		void set_private_ip_adddress(string private_ip_adddress_);

	const vector<string> *get_security_group_ids();

		void set_security_group_id(vector<string> security_group_id_set);

	const string get_key_name();

		void set_key_name(string kay_name_);
	};

}
#endif
