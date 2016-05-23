#include <vector>
#include <string>

using namespace std;

class delete_snapshot_request
{
private:
	string snapshot_id;

public:
	string get_snapshot_id();

	void set_snapshot_id(string snapshot_id_);
};