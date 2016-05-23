#include <vector>
#include <string>

using namespace std;

class create_snapshot_request
{
private:
	string volume_id;

public:
	string get_volume_id();

	void set_volume_id(string volume_id_);
};