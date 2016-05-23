#include <vector>
#include <string>

using namespace std;

class create_volume_request
{
private:
	string snapshot_id;
	int size;

public:

	create_volume_request()
	{
		snapshot_id = "";
		size = -1;
	}

	string get_snapshot_id()
	{
		return snapshot_id;
	}

	void set_snapshot_id(string snapshot_id_)
	{
		snapshot_id = snapshot_id_;
	}

	int get_size()
	{
		return size;
	}
	
	void set_size(int size_)
	{
		size = size_;
	}
};