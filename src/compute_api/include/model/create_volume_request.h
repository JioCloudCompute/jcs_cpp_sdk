#include <vector>
#include <string>

using namespace std;

class create_volume_request
{
private:
	string snapshot_id;
	int size;

public:
	string get_snapshot_id();

	void set_snapshot_id(string snapshot_id_);

	int get_size();
	
	void set_size(int size_);
};