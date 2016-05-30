#include "src/compute_api/include/model/describe_instance_types_request.h"

using namespace std;
using namespace model;


model::describe_instance_types_request::describe_instance_types_request(){}

const vector<string> *model::describe_instance_types_request::get_instance_type_ids() const
{
	return &instance_type_ids;
}

void model::describe_instance_types_request::set_instance_types_ids(const vector<string>& instance_type_id_set)
{
	instance_type_ids.insert(instance_type_ids.end(), instance_type_id_set.begin(), instance_type_id_set.end());
}