#include <vector>
#include <string>

using namespace std;

class describe_instance_types_request
{
private:
	vector<string> instance_type_ids;

public:
	vector<string> get_instance_types_ids();

	void set_instance_types_ids(vector<string>instance_type_id_set);
};