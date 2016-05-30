#include "src/compute_api/include/model/describe_volumes_request.h"

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

const int model::describe_volumes_request::get_max_results() const
{
	return max_results;
}

void model::describe_volumes_request::set_max_results(const int& max_results_)
{
	max_results = max_results_;
}

const string model::describe_volumes_request::get_next_token() const
{
	return next_token;
}

void model::describe_volumes_request::set_next_token(const string& next_token_)
{
	next_token = next_token_;
}

const bool model::describe_volumes_request::get_detail() const
{
	return detail;
}

void model::describe_volumes_request::set_detail(const bool& detail_)
{
	detail = detail_;
}
