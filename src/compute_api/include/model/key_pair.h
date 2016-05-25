#include <string>
using namespace std;
namespace model
{

	class key_pair
	{
	private:
		string key_name;
		string key_fingerprint;
	public:
		key_pair(string key_name_, string key_fingerprint_)
		{
			key_name = key_name_;
			key_fingerprint = key_fingerprint_;
		}
		key_pair(){}

		const string get_key_name()
		{
			return key_name;
		}

		const string get_key_fingerprint()
		{
			return key_fingerprint;
		}
	};
}