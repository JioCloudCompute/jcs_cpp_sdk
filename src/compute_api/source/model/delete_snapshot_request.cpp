#include "src/compute_api/include/model/delete_snapshot_request.h"

using namespace std;
using namespace model;

model::delete_snapshot_request::delete_snapshot_request(){}

const string model::delete_snapshot_request::get_snapshot_id() const
{
	return snapshot_id;
}

void model::delete_snapshot_request::set_snapshot_id(const string& snapshot_id_)
{
	snapshot_id = snapshot_id_;
}
