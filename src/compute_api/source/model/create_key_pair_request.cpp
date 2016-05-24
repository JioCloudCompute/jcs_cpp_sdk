#include "src/compute_api/include/model/create_key_pair_request.h"
using namespace std;
using namespace model;

model::create_key_pair_request::create_key_pair_request()
{
	key_name = "";
}
const string model::create_key_pair_request::get_key_name()
{
	return key_name;
}

void model::create_key_pair_request::set_key_name(string key_name_)
{
	key_name = key_name_;
}
int main(){}
