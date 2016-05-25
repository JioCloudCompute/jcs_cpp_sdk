#ifndef DETACH_VOLUMER_H
#define DETACH_VOLUMER_H
#include <string>
using namespace std;
namespace model
{
	class detach_volume_response
	{
	private:
		string status;
		string request_id;
	public:
		detach_volume_response(const string &xml_doc);

		const string get_request_id() 
		{
			return request_id;
		}
		
		string get_status() const
		{
			return status;
		}
	};
}
#endif
