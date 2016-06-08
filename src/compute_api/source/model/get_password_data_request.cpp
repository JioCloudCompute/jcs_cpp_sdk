#include "src/compute_api/include/model/get_password_data_request.h"

using namespace std;
using namespace model;

const string model::get_password_data_request::get_instance_id() const
{
	return instance_id;
}

void model::get_password_data_request::set_instance_id(const string& instance_id_)
{
	instance_id = instance_id_;
}

const string model::get_password_data_request::get_private_key_file () const
{
	return private_key_file;
}

void model::get_password_data_request::set_private_key_file(const string& private_key_file_)
{
	private_key_file = private_key_file_;
}

const string model::get_password_data_request::get_passphrase() const
{
	return passphrase;
}

void model::get_password_data_request::set_passphrase(const string& passphrase_)
{
	passphrase = passphrase_;
}



