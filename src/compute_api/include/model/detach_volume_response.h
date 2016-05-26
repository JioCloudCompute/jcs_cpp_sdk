#ifndef DETACH_VOLUMER_H
#define DETACH_VOLUMER_H
#include <string>
using namespace std;
namespace model
{
	class detach_volume_response
	{
	private:
		string request_id;
		string device;
		string instance_id;
		bool delete_on_termination;
		string status;
		string volume_id;
	public:
		detach_volume_response(const string &xml_doc);
		detach_volume_response(){}
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
		const string get_instance_id()
		{
			return instance_id;
		}
		const string get_volume_id()
		{
			return  volume_id;
		}
		const bool get_delete_on_termination()
		{
			return delete_on_termination;
		}
	};

}
#endif

