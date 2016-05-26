#ifndef CREATE_SNAPSHOTR_H
#define CREATE_SNAPSHOTR_H
#include <string>
using namespace std;
namespace model
{
	class create_snapshot_response
	{
	private:
		string request_id;
		string status;
		string snapshot_id;
		float volume_size;
		string volume_id;
		string start_time;

	public:
		create_snapshot_response(const string &xml_doc);
		create_snapshot_response(){}

		const string get_request_id()
		{
			return request_id;
		}
		const string get_status()
		{
			return status;
		}
		const string get_snapshot_id()
		{
			return snapshot_id;
		}
		const float get_volume_size()
		{
			return volume_size;
		}
		const string get_volume_id()
		{
			return volume_id;
		}
		const string get_start_time()
		{
			return start_time;
		}

	};
}
#endif

