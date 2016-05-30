#include "src/compute_api/include/model/delete_volume_request.h"

using namespace std;
using namespace model;

model::delete_volume_request::delete_volume_request(){}

const string model::delete_volume_request::get_volume_id() const
{
	return volume_id;
}

void model::delete_volume_request::set_volume_id(const string& volume_id_)
{
	volume_id = volume_id_;
}
