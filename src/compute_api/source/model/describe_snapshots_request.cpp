#include <vector>
#include <string>

using namespace std;

class describe_snapshots_request
{
private:
	vector<string> snapshot_ids;
	int max_results;
	string next_token;
	bool detail;

public:

	describe_snapshots_request()
	{
		snapshot_ids = vector<string>();
		max_results = -1;
		next_token = "";
		detail = true;
	}

	vector<string> get_snapshot_ids()
	{
		return snapshot_ids;
	}

	void set_snapshot_ids(vector<string> snapshot_id_set)
	{
		for(int i=0 ; i<snapshot_id_set.size() ; i++)
		{
			snapshot_ids.push_back(snapshot_id_set[i]);
		}
	}

	int get_max_results()
	{
		return max_results;
	}

	void set_max_results(int max_results_)
	{
		max_results = max_results_;
	}

	string get_next_token()
	{
		return next_token;
	}

	void set_next_token(string next_token_)
	{
		next_token = next_token_;
	}

	bool set_detail()
	{
		return detail;
	}

	void set_detail(bool detail_)
	{
		detail = detail_;
	}

};