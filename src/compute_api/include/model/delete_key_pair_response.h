#include <string>
using namespace std;
namespace model
{
	class delete_key_pair_response
	{
	private:
		bool result;
		string request_id;
	public:
		create_key_pair_response(const string xml_doc);

		const string get_request_id()
		{
			return request_id;
		}

		const bool get_result()
		{
			return result;
		}

	};

}