#include <string>
using namespace std;
namespace model
{
	class update_delete_on_termination_flag_response
	{
	private:
		string request_id;
		string instance_id;
		string volume_id;
		bool delete_on_termination;

	public:
		update_delete_on_termination_flag_response(const string xml_doc);

		const string get_request_id()
		{
			return request_id;
		}
		const string get_instance_id()
		{
			return instance_id;
		}
		const string get_volume_id()
		{
			return volume_id;
		}
		const bool get_delete_on_termination()
		{
			return delete_on_termination;
		}

	};

}