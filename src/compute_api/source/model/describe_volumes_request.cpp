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
#include "model/describe_volumes_request.hpp"

using namespace std;
using namespace model;

model::describe_volumes_request::describe_volumes_request()
{
	max_results = -1;
	detail = true;
}

const vector<string> *model::describe_volumes_request::get_volume_ids() const
{
	return &volume_ids;
}

void model::describe_volumes_request::set_volume_ids(const vector<string>& volume_id_set)
{
	volume_ids.insert(volume_ids.begin(), volume_id_set.begin(), volume_id_set.end());
}

int model::describe_volumes_request::get_max_results() const
{
	return max_results;
}

void model::describe_volumes_request::set_max_results(int max_results_)
{
	max_results = max_results_;
}

const string& model::describe_volumes_request::get_next_token() const
{
	return next_token;
}

void model::describe_volumes_request::set_next_token(const string& next_token_)
{
	next_token = next_token_;
}

bool model::describe_volumes_request::get_detail() const
{
	return detail;
}

void model::describe_volumes_request::set_detail(bool detail_)
{
	detail = detail_;
}
