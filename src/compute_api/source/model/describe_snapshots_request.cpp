#include "src/compute_api/include/model/describe_snapshots_request.h"

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
	for(int i=0 ; i<snapshot_id_set.size() ; i++)
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
