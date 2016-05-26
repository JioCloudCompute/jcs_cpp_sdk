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
		vector<model::instance_type>instance_type_set;

	public:
		describe_instance_types_response(const string &xml_doc);
		describe_instance_types_response(){}

		const string get_request_id()
		{
			return request_id;
		}
		const vector<model::instance_type> get_instance_types()
		{
			return instance_type_set;
		}
	};
}
#endif

