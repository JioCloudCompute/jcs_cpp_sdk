#include <string>
#include <map>
using namespace std;

namespace model
{
	class volume
	{
	private:
		string status;
		string volume_id;
		string device;
		string instance_id;
		string snapshot_id;
		string create_time;
		float size;

	public:
		volume(string status, string volume_id, string device, string instance_id, string snapshot_id, string create_time, float size);
		const string get_status()
		{
			return status;
		}

		const string get_volume_id()
		{
			return volume_id;
		}

		const string get_device()
		{
			return device;
		}

		const string get_instance_id()
		{
			return instance_id;
		}

		const string get_snapshot_id()
		{
			return snapshot_id;
		}
		const string get_create_time()
		{
			return create_time;
		}
		float string get_size()
		{
			return size;
		}

	};
}