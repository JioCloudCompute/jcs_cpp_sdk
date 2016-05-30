#include "src/compute_api/include/model/update_delete_on_termination_flag_request.h"

using namespace std;
using namespace model;


model::update_delete_on_termination_flag_request::update_delete_on_termination_flag_request()
{
	delete_on_termination = false;
}

const string model::update_delete_on_termination_flag_request::get_volume_id() const
{
	return volume_id;
}

void model::update_delete_on_termination_flag_request::set_volume_id(const string& volume_id_)
{
	volume_id = volume_id_;
}

const bool model::update_delete_on_termination_flag_request::get_delete_on_termination() const
{
	return delete_on_termination;
}

void model::update_delete_on_termination_flag_request::set_delete_on_termination(const bool& delete_on_termination_)
{
	delete_on_termination = delete_on_termination_;
}
