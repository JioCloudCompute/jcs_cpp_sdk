#include "src/compute_api/include/model/detach_volume_request.h"

using namespace std;
using namespace model;

model::detach_volume_request::detach_volume_request()
{
	instance_id = "";
	volume_id = "";
}

const string model::detach_volume_request::get_instance_id()
{
	return instance_id;
}

void model::detach_volume_request::set_instance_id(string instance_id_)
{
	instance_id = instance_id_;
}

const string model::detach_volume_request::get_volume_id()
{
	return volume_id;
}

void model::detach_volume_request::set_volume_id(string volume_id_)
{
	volume_id = volume_id_;
}
