#include "src/compute_api/include/model/create_snapshot_request.h"

using namespace std;
using namespace model;


const string model::create_snapshot_request::get_volume_id() const
{
	return volume_id;
}

void model::create_snapshot_request::set_volume_id(const string& volume_id_)
{
	volume_id = volume_id_;
}
