#include <vector>
#include <string>

using namespace std;

class show_delete_on_termination_flag_request
{
private:
	string volume_id;

public:
	string get_volume_id();

	void set_volume_id(string volume_id_);
};