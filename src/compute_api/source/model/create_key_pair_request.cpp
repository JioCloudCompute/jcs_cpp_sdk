#include "src/compute_api/include/model/create_key_pair_request.h"
using namespace std;
using namespace model;


const string model::create_key_pair_request::get_key_name() const
{
	return key_name;
}

void model::create_key_pair_request::set_key_name(const string& key_name_)
{
	key_name = key_name_;
}
