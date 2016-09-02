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
#include "model/describe_snapshots_request.hpp"

using namespace std;
using namespace model;

model::describe_snapshots_request::describe_snapshots_request()
{
	max_results = -1;
	detail = true;
}

const vector<string> *model::describe_snapshots_request::get_snapshot_ids() const
{
	return &snapshot_ids;
}

void model::describe_snapshots_request::set_snapshot_ids(const vector<string>& snapshot_id_set)
{
	for(size_t i=0 ; i<snapshot_id_set.size() ; i++)
	{
		snapshot_ids.push_back(snapshot_id_set[i]);
	}
}

const int model::describe_snapshots_request::get_max_results() const
{
	return max_results;
}

void model::describe_snapshots_request::set_max_results(const int& max_results_)
{
	max_results = max_results_;
}

const string model::describe_snapshots_request::get_next_token() const
{
	return next_token;
}

void model::describe_snapshots_request::set_next_token(const string &next_token_)
{
	next_token = next_token_;
}

const bool model::describe_snapshots_request::get_detail() const
{
	return detail;
}

void model::describe_snapshots_request::set_detail(const bool& detail_)
{
	detail = detail_;
}
