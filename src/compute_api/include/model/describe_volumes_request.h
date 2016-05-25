#ifndef DESCRIBE_VOLUMES_H
#define DESCRIBE_VOLUMES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class describe_volumes_request
	{
	private:
		vector<string> volume_ids;
		int max_results;
		string next_token;
		bool detail;

	public:
		describe_volumes_request();
	const vector<string> *get_volume_ids();

		void set_volume_ids(vector<string> volume_id_set);

	const int get_max_results();

		void set_max_results(int max_results_);

	const string get_next_token();

		void set_next_token(string next_token_);

		bool set_detail();

		void set_detail(bool detail_);
		
	};
}
#endif

