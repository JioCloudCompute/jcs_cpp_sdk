#include "src/compute_api/include/model/import_key_pair_request.h"

using namespace std;
using namespace model;


model::import_key_pair_request::import_key_pair_request()
{
	key_name = "";
	public_key_material = "";
}

const string model::import_key_pair_request::get_key_name()
{
	return key_name;
}

void model::import_key_pair_request::set_key_name(string key_name_)
{
	key_name = key_name_;
}

const string model::import_key_pair_request::get_public_key_material()
{
	return public_key_material;
}

void model::import_key_pair_request::set_public_key_material(string public_key_material_)
{
	public_key_material = public_key_material_;
}
