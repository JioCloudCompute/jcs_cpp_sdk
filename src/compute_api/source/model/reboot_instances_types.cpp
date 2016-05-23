#include <vector>
#include <string>

using namespace std;

class reboot_instances_request
{
private:
	vector<string> instance_ids;

public:

	reboot_instances_request()
	{
		instance_ids = vector<string>();
	}

	vector<string> get_instance_ids()
	{
		return instance_ids;
	}

	void set_instance_ids(vector<string>instance_id_set)
	{
		for(int i=0 ; i<instance_id_set.size() ; i++)
		{
			instance_ids.push_back(instance_id_set[i]);
		}
	}
};