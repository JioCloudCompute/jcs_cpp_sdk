#include <vector>
#include <string>

using namespace std;

class show_delete_on_termination_flag_request
{
private:
	string volume_id;

public:

	show_delete_on_termination_flag_request()
	{
		volume_id "";
	}

	string get_volume_id()
	{
		return volume_id;
	}

	void set_volume_id(string volume_id_)
	{
		volume_id = volume_id_;
	}
};