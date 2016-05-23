#include <vector>
#include <string>

using namespace std;

class delete_key_pair_request
{
private:
	string key_name;
	string public_key_material;

public:
	string get_key_name();

	void set_key_name(string key_name_);

	string get_public_key_material();

	void set_public_key_material(string public_key_material_);
};