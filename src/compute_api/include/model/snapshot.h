#include <string>
using namespace std;

namespace model
{
	class snapshot
	{
	private:
		string status;
		string snapshot_id;
		float volume_size;
		string volume_id;
		string start_time;

	public:
		snapshot(string status_, string snapshot_id_, float volume_size_, string volume_id_, string start_time_)
		{
			status = status_;
			snapshot_id = snapshot_id_;
			volume_size = volume_size_;
			volume_id = volume_id_;
			start_time = start_time;
		}
		snapshot(){}
		const string get_snapshot_id()
		{
			return snapshot_id;
		}

		const string get_volume_id()
		{
			return volume_id;
		}

		const string get_status()
		{
			return status;
		}

		const float get_volume_size()
		{
			return volume_size;
		}

		const string get_start_time()
		{
			return start_time;
		}
	};
}