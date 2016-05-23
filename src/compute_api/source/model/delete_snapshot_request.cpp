#include <vector>
#include <string>

using namespace std;

class delete_snapshot_request
{
private:
	string snapshot_id;

public:

	delete_snapshot_request()
	{
		snapshot_id = "";
	}

	string get_snapshot_id()
	{
		return snapshot_id;
	}

	void set_snapshot_id(string snapshot_id_)
	{
		snapshot_id = snapshot_id_;
	}
};