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
