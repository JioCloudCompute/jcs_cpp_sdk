#ifndef DESCRIBE_INSTANCE_TYPESR_H
#define DESCRIBE_INSTANCE_TYPESR_H
#include <map>
#include "src/compute_api/include/model/instance_type.h"
using namespace std;
using namespace model;

namespace model
{
	class describe_instance_types_response
	{
	private:
		string request_id;
		map<string, model::instance_type>instance_type_set;

	public:
		describe_instance_types_response(const string &xml_doc);

		const string get_request_id()
		{
			return request_id;
		}
		const map<string, model::instance_type> get_instance_types()
		{
			return instance_type_set;
		}
	};
}
#endif

