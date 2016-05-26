#ifndef REBOOT_INSTANCE_H
#define REBOOT_INSTANCE_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class reboot_instances_request
	{
	private:
		vector<string> instance_ids;

	public:
		reboot_instances_request();
		const vector<string> *get_instance_ids();

		void set_instance_ids(vector<string>instance_id_set);
	};
}
#endif
