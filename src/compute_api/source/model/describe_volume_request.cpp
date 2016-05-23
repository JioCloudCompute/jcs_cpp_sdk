#include <vector>
#include <string>

using namespace std;

class describe_volumes_request
{
private:
	vector<string> volume_ids;
	int max_results;
	string nect_token;
	bool detail;

public:
	vector<string> get_volume_ids();

	void set_volume_ids(vector<string> volume_id_set);

	int get_max_results();

	void set_max_results(int max_results_);

	string get_nest_token();

	void set_next_token(string next_token_);

	bool set_detail();

	void set_detail(bool detail_);
	
};