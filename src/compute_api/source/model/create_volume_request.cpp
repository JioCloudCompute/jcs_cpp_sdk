#include "src/compute_api/include/model/create_volume_request.h"

using namespace std;
using namespace model;

model::create_volume_request::create_volume_request()
{
	size = -1;
}

const string model::create_volume_request::get_snapshot_id() const
{
	return snapshot_id;
}

void model::create_volume_request::set_snapshot_id(const string& snapshot_id_)
{
	snapshot_id = snapshot_id_;
}

const int model::create_volume_request::get_size() const
{
	return size;
}

void model::create_volume_request::set_size(const int& size_)
{
	size = size_;
}
