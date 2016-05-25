#ifndef DELETE_KEY_PAIR_H
#define DELETE_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class delete_key_pair_request
	{
	private:
		string key_name;

	public:
		delete_key_pair_request();
	const string get_key_name();

		void set_key_name(string key_name_);
	};
}
#endif

