#include <string>
using namespace std;
namespace model
{
	class create_volume_response
	{
	private:
		string request_id;
		string status;
		string volume_id;
		string snapshot_id;
		float size;
		string create_time;

	public:
		create_volume_response(const string xml_doc);

		const string get_request_id()
		{
			return request_id;
		}
		const string get_status()
		{
			return status;
		}
		const string get_volume_id()
		{
			return volume_id;
		}
		const string get_snapshot_id()
		{
			return snapshot_id;
		}
		const float get_size()
		{
			return size;
		}

		const string get_create_time()
		{
			return create_time;
		}

	};

}