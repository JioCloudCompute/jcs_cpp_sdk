#ifndef START_INSTANCE_H
#define START_INSTANCE_H
#include <vector>
#include <string>

using namespace std;

namespace model
{
	class start_instances_request
	{
	private:
		vector<string> instance_ids;

	public:
		start_instances_request();
	const vector<string> *get_instance_ids();

		void set_instance_ids(vector<string>instance_id_set);
	};
}
#endif
