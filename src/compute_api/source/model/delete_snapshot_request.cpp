#include "src/compute_api/include/model/delete_snapshot_request.h"

using namespace std;
using namespace model;

model::delete_snapshot_request::delete_snapshot_request()
{
	snapshot_id = "";
}

const string model::delete_snapshot_request::get_snapshot_id()
{
	return snapshot_id;
}

void model::delete_snapshot_request::set_snapshot_id(string snapshot_id_)
{
	snapshot_id = snapshot_id_;
}
