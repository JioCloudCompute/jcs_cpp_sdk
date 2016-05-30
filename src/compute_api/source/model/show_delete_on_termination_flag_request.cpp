#include "src/compute_api/include/model/show_delete_on_termination_flag_request.h"

using namespace std;
using namespace model;


model::show_delete_on_termination_flag_request::show_delete_on_termination_flag_request(){}

const string model::show_delete_on_termination_flag_request::get_volume_id() const
{
	return volume_id;
}

void model::show_delete_on_termination_flag_request::set_volume_id(const string& volume_id_)
{
	volume_id = volume_id_;
}
