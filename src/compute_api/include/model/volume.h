#ifndef VOLUME_H
#define VOLUME_H
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
		volume(string status_, string volume_id_, string device_, string instance_id_, string snapshot_id_, string create_time_, float size_)
		{
			status = status_;
			volume_id = volume_id_;
			device = device_;
			instance_id = instance_id_;
			snapshot_id = snapshot_id_;
			create_time = create_time_;
			size = size_;

		}

		volume(){}
		
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
		const float get_size()
		{
			return size;
		}

	};
}
#endif
