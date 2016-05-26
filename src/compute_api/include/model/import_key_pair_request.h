#ifndef IMPORT_KEY_PAIR_H
#define IMPORT_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class import_key_pair_request
	{
	private:
		string key_name;
		string public_key_material;

	public:
		import_key_pair_request();
		const string get_key_name();

		void set_key_name(string key_name_);

		const string get_public_key_material();

		void set_public_key_material(string public_key_material_);
	};
}
#endif
