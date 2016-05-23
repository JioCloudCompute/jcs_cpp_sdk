#include <vector>
#include <string>

using namespace std;

class terminate_instances_request
{
private:
	vector<string> instance_ids;

public:
	vector<string> get_instance_ids();

	void set_instance_ids(vector<string>instance_id_set);
};