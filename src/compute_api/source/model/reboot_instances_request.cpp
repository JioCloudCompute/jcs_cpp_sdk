#include "src/compute_api/include/model/reboot_instances_request.h"

using namespace std;
using namespace model;

model::reboot_instances_request::reboot_instances_request(){}

const vector<string> *model::reboot_instances_request::get_instance_ids() const
{
	return &instance_ids;
}

void model::reboot_instances_request::set_instance_ids(const vector<string>& instance_id_set)
{
	instance_ids.insert(instance_ids.end(), instance_id_set.begin(), instance_id_set.end());
}
