#ifndef DESCRIBE_SNAPSHOTS_H
#define DESCRIBE_SNAPSHOTS_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class describe_snapshots_request
	{
	private:
		vector<string> snapshot_ids;
		int max_results;
		string next_token;
		bool detail;

	public:
		describe_snapshots_request();
		const vector<string> *get_snapshot_ids();

		void set_snapshot_ids(vector<string> snapshot_id_set);

		const int get_max_results();

		void set_max_results(int max_results_);

		const string get_next_token();

		void set_next_token(string next_token_);

		bool set_detail();

		void set_detail(bool detail_);

	};
}
#endif
