#include "src/compute_api/include/model/create_volume_request.h"

using namespace std;
using namespace model;

model::create_volume_request::create_volume_request()
{
	snapshot_id = "";
	size = -1;
}

const string model::create_volume_request::get_snapshot_id()
{
	return snapshot_id;
}

void model::create_volume_request::set_snapshot_id(string snapshot_id_)
{
	snapshot_id = snapshot_id_;
}

const int model::create_volume_request::get_size()
{
	return size;
}

void model::create_volume_request::set_size(int size_)
{
	size = size_;
}
