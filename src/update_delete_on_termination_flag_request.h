#include <vector>
#include <string>

using namespace std;

class update_delete_on_termination_flag_request
{
private:
	string volume_id;
	bool delete_on_termination;

public:
	string get_volume_id();

	void set_volume_id(string volume_id_);
	
	bool get_delete_on_termination_flag();
	
	void get_delete_on_termination_flag(bool delete_on_termination_);

};