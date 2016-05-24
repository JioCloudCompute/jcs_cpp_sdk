#include "src/compute_api/include/model/describe_instance_types_request.h"

using namespace std;
using namespace model;


model::describe_instance_types_request::describe_instance_types_request()
{
	instance_type_ids = vector<string>();
}

const vector<string> model::describe_instance_types_request::get_instance_types_ids()
{
	return instance_type_ids;
}

void model::describe_instance_types_request::set_instance_types_ids(vector<string>instance_type_id_set)
{
	for(int i=0 ; i<instance_type_id_set.size() ; i++)
	{
		instance_type_ids.push_back(instance_type_id_set[i]);
	}
}
