#include <string>
using namespace std;
namespace model
{
	class create_snapshot_response
	{
	private:
		string key_fingerprint;
		string key_material;
		string key_name;
		string request_id;
	public:
		create_key_pair_response(const string xml_doc);

		const string get_key_fingerprint()
		{
			return key_fingerprint;
		}

		const string get_key_material()
		{
			return key_material;
		}

		const string get_key_name()
		{
			return key_name;
		}

		const string get_request_id()
		{
			return request_id;
		}
	};

}