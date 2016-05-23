#include <vector>
#include <string>

using namespace std;

class describe_volumes_request
{
private:
	vector<string> volume_ids;
	int max_results;
	string next_token;
	bool detail;

public:

	describe_volumes_request()
	{
		volume_ids = vector<string>();
		max_results = -1;
		next_token = "";
		detail = true;
	}

	vector<string> get_volume_ids()
	{
		return volume_ids;
	}

	void set_volume_ids(vector<string> volume_id_set)
	{
		for(int i=0 ; i<volume_id_set.size() ; i++)
		{
			volume_ids.push_back(volume_id_set[i]);
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