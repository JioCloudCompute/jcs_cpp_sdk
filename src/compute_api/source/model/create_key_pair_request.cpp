#include <vector>
#include <string>

using namespace std;

class create_key_pair_request
{
private:
	string key_name;

public:
	create_key_pair_request()
	{
		key_name = "";
	}
	string get_key_name()
	{
		return key_name;
	}

	void set_key_name(string key_name_)
	{
		key_name = key_name_;
	}
};