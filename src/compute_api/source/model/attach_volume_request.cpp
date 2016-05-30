#include "src/compute_api/include/model/attach_volume_request.h"

using namespace std;
using namespace model;

attach_volume_request(){}

const string model::attach_volume_request::get_instance_id() const
{
	return instance_id;
}

void model::attach_volume_request::set_instance_id(const string& instance_id_)
{
	instance_id = instance_id_;
}

const string model::attach_volume_request::get_volume_id() const
{
	return volume_id;
}

void model::attach_volume_request::set_volume_id(const string &volume_id_)
{
	volume_id = volume_id_;
}

const string model::attach_volume_request::get_device() const
{
	return device;
}

void model::attach_volume_request::set_device(const string& device_)
{
	device = device_;
}
