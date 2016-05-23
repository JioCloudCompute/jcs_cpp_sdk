#include <vector>
#include <string>

using namespace std;

class delete_volume_request
{
private:
	string volume_id;

public:
	string get_volume_id();

	void set_volume_id(string volume_id_);
};