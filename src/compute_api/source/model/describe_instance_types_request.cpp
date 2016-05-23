#include <vector>
#include <string>

using namespace std;

class describe_instance_types_request
{
private:
	vector<string> instance_type_ids;

public:

	describe_instance_types_request()
	{
		instance_type_ids = vector<string();
	}

	vector<string> get_instance_types_ids()
	{
		return instance_type_ids;
	}

	void set_instance_types_ids(vector<string>instance_type_id_set)
	{
		for(int i=0 ; i<instance_type_id_set.size() ; i++)
		{
			instance_type_ids.push_back(instance_type_id_set[i]);
		}
	}
};