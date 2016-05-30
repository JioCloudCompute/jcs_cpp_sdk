#include "src/compute_api/include/model/terminate_instances_request.h"

using namespace std;
using namespace model;

model::terminate_instances_request::terminate_instances_request(){}

const vector<string> *model::terminate_instances_request::get_instance_ids() const
{
	return &instance_ids;
}

void model::terminate_instances_request::set_instance_ids(const vector<string>& instance_id_set)
{
	instance_ids.insert(instance_id_set.end(), instance_id_set.begin(), instance_id_set.end());
}
