#ifndef CREATE_KEY_PAIR_H
#define CREATE_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class create_key_pair_request
	{
	private:
		string key_name;

	public:
		create_key_pair_request();
		create_key_pair();
	const string get_key_name();

		void set_key_name(string key_name_);
	};
}
#endif

