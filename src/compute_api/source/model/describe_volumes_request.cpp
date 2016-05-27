#include "src/compute_api/include/model/describe_volumes_request.h"

using namespace std;
using namespace model;

model::describe_volumes_request::describe_volumes_request()
{
	volume_ids = vector<string>();
	max_results = -1;
	next_token = "";
	detail = true;
}

const vector<string> *model::describe_volumes_request::get_volume_ids()
{
	return &volume_ids;
}

void model::describe_volumes_request::set_volume_ids(vector<string> volume_id_set)
{
	for(int i=0 ; i<volume_id_set.size() ; i++)
	{
		volume_ids.push_back(volume_id_set[i]);
	}
}

const int model::describe_volumes_request::get_max_results()
{
	return max_results;
}

void model::describe_volumes_request::set_max_results(int max_results_)
{
	max_results = max_results_;
}

const string model::describe_volumes_request::get_next_token()
{
	return next_token;
}

void model::describe_volumes_request::set_next_token(string next_token_)
{
	next_token = next_token_;
}

const bool model::describe_volumes_request::get_detail()
{
	return detail;
}

void model::describe_volumes_request::set_detail(bool detail_)
{
	detail = detail_;
}
