#include <vector>
#include <string>

using namespace std;

class update_delete_on_termination_flag_request
{
private:
	string volume_id;
	bool delete_on_termination;

public:

	update_delete_on_termination_flag_request()
	{
		volume_id = "";
		delete_on_termination = false;
	}

	string get_volume_id()
	{
		return volume_id;
	}

	void set_volume_id(string volume_id_)
	{
		volume_id = volume_id_;
	}

	bool get_delete_ont_termination()
	{
		return delete_on_termination;
	}

	void set_delete_on_termination(bool delete_on_termination_)
	{
		delete_on_termination = delete_on_termination_;
	}
};