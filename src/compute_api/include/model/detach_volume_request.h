#ifndef DETACH_VOLUME_H
#define DETACH_VOLUME_H
#include <vector>
#include <string>

using namespace std;

namespace model
{
	class detach_volume_request
	{
	private:
		string instance_id;
		string volume_id;

	public:
		detach_volume_request();
		const string get_instance_id();

		void set_instance_id(string instance_id_);

		const string get_volume_id();

		void set_volume_id(string volume_id_);

	};
}
#endif
