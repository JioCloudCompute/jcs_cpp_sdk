#include <vector>
#include <string>

using namespace std;

class delete_key_pair_request
{
private:
	string key_name;
	string public_key_material;

public:

	delete_key_pair_request()
	{
		key_name = "";
		public_key_material = "";
	}

	string get_key_name()
	{
		return key_name;
	}

	void set_key_name(string key_name_)
	{
		key_name = key_name_;
	}

	string get_public_key_material()
	{
		return public_key_material;
	}

	void set_public_key_material(string public_key_material_)
	{
		public_key_material = public_key_material_;
	}
};