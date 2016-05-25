#ifndef DESCRIBE_INSTANCES_TYPES_H
#define DESCRIBE_INSTANCES_TYPES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class describe_instance_types_request
	{
	private:
		vector<string> instance_type_ids;

	public:
		describe_instance_types_request();
	const vector<string> *get_instance_types_ids();

		void set_instance_types_ids(vector<string>instance_type_id_set);
	};
}
#endif

