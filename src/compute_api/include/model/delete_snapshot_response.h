#include <string>
using namespace std;
namespace model
{
	class delete_snapshot_response
	{
	private:
		string request_id;
		string result;

	public:
		delete_snapshot_response(const string xml_doc);

		const string get_request_id()
		{
			return request_id;
		}
		const string get_result()
		{
			return result;
		}

	};

}