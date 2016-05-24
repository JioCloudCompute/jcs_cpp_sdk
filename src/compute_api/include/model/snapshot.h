#include <string>
using namespace std;

model
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
		snapshot(string status, string snapshot_id, string volume_size, string volume_id, string start_time);
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
			return previous_state;
		}

		const string get_start_time()
		{
			return start_time;
		}
	};
}