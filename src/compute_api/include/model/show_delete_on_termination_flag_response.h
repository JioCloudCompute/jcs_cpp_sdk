#ifndef SHOW_DELETER_H
#define SHOW_DELETER_H
#include <string>
using namespace std;
namespace model
{
	class show_delete_on_termination_flag_response
	{
	private:
		string request_id;
		string instance_id;
		string volume_id;
		bool delete_on_termination;

	public:
		show_delete_on_termination_flag_response(const string &xml_doc);
		show_delete_on_termination_flag_response(){}

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
#endif
