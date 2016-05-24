#include "src/compute_api/include/model/reboot_instances_request.h"

using namespace std;
using namespace model;

model::reboot_instances_request::reboot_instances_request()
{
	instance_ids = vector<string>();
}

const vector<string> model::reboot_instances_request::get_instance_ids()
{
	return instance_ids;
}

void model::reboot_instances_request::set_instance_ids(vector<string>instance_id_set)
{
	for(int i=0 ; i<instance_id_set.size() ; i++)
	{
		instance_ids.push_back(instance_id_set[i]);
	}
}
int main(){}
