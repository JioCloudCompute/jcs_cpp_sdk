#include "src/compute_api/include/model/delete_key_pair_request.h"

using namespace std;
using namespace model;

model::delete_key_pair_request::delete_key_pair_request(){}

const string model::delete_key_pair_request::get_key_name() const
{
	return key_name;
}

void model::delete_key_pair_request::set_key_name(const string& key_name_)
{
	key_name = key_name_;
}
