#include "src/compute_api/include/model/detach_volume_request.h"

using namespace std;
using namespace model;

model::detach_volume_request::detach_volume_request(){}

const string model::detach_volume_request::get_instance_id() const
{
	return instance_id;
}

void model::detach_volume_request::set_instance_id(const string& instance_id_)
{
	instance_id = instance_id_;
}

const string model::detach_volume_request::get_volume_id() const
{
	return volume_id;
}

void model::detach_volume_request::set_volume_id(const string& volume_id_)
{
	volume_id = volume_id_;
}
