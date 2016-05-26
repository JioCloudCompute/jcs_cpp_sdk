#include "src/compute_api/include/model/describe_snapshots_request.h"

using namespace std;
using namespace model;

model::describe_snapshots_request::describe_snapshots_request()
{
	snapshot_ids = vector<string>();
	max_results = -1;
	next_token = "";
	detail = true;
}

const vector<string> *model::describe_snapshots_request::get_snapshot_ids()
{
	return &snapshot_ids;
}

void model::describe_snapshots_request::set_snapshot_ids(vector<string> snapshot_id_set)
{
	for(int i=0 ; i<snapshot_id_set.size() ; i++)
	{
		snapshot_ids.push_back(snapshot_id_set[i]);
	}
}

const int model::describe_snapshots_request::get_max_results()
{
	return max_results;
}

void model::describe_snapshots_request::set_max_results(int max_results_)
{
	max_results = max_results_;
}

const string model::describe_snapshots_request::get_next_token()
{
	return next_token;
}

void model::describe_snapshots_request::set_next_token(string next_token_)
{
	next_token = next_token_;
}

bool model::describe_snapshots_request::get_detail()
{
	return detail;
}

void model::describe_snapshots_request::set_detail(bool detail_)
{
	detail = detail_;
}
