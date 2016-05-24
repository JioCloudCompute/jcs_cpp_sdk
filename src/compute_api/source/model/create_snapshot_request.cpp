#include "src/compute_api/include/model/create_snapshot_request.h"

using namespace std;
using namespace model;

model::create_snapshot_request::create_snapshot_request()
{
	volume_id = "";
}

const string model::create_snapshot_request::get_volume_id()
{
	return volume_id;
}

void model::create_snapshot_request::set_volume_id(string volume_id_)
{
	volume_id = volume_id_;
}
