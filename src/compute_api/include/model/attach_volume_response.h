#include <string>
using namespace std;
namespace model
{
	class attach_volume_response
	{
	private:
		string request_id;
		string status;
		string device;
	public:
		attach_volume_response(const string xml_doc);
		const string get_request_id() 
		{
			return request_id;
		}
		const string get_status() 
		{
			return status;
		}
		const string get_device()
		{
			return device;
		}
	};

}