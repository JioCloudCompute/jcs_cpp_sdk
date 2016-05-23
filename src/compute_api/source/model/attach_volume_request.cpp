#include "src/compute_api/include/model/attach_volume_request.h"

using namespace std;

attach_volume_request::attach_volume_request()
{
	instance_id = "";
	volume_id = "";
	device = "";
}

string attach_volume_request::get_instance_id()
{
	return instance_id;
}

void attach_volume_request::set_instance_id(string instance_id_)
{
	instance_id = instance_id_;
}

string attach_volume_request::get_volume_id()
{
	return volume_id;
}

void attach_volume_request::set_volume_id(string volume_id_)
{
	volume_id = volume_id_;
}

string attach_volume_request::get_device()
{
	return device;
}

void attach_volume_request::set_device(string device_)
{
	device = device_;
}

