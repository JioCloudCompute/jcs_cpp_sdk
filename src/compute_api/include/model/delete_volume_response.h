#include <string>
using namespace std;
namespace model
{
	class delete_volume_response
	{
	private:
		string request_id;
		bool result;

	public:
		delete_volume_response(const string xml_doc);

		const string get_request_id()
		{
			return request_id;
		}
		const bool get_status()
		{
			return result;
		}

	};

}