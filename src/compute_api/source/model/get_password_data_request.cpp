/*****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
#include "model/get_password_data_request.hpp"

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



