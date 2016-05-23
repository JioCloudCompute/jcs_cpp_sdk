#include <vector>
#include <string>

using namespace std;

class create_key_pair_request
{
private:
	string key_name;

public:
	string get_key_name();

	void set_key_name(string key_name_);
};