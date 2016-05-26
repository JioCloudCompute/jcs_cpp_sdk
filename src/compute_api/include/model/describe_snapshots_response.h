#ifndef DESCRIBE_SNAPSHOTSR_H
#define DESCRIBE_SNAPSHOTSR_H
#include <map>
#include "src/compute_api/include/model/snapshot.h"
using namespace std;
using namespace model;

namespace model
{
	class describe_snapshots_response
	{
	private:
		string request_id;
		vector<model::snapshot>snapshot_set;

	public:
		describe_snapshots_response(const string &xml_doc);
		describe_snapshots_response(){}

		const string get_request_id()
		{
			return request_id;
		}
		const vector<model::snapshot> get_snapshot_set()
		{
			return snapshot_set;
		}
	};
}
#endif

