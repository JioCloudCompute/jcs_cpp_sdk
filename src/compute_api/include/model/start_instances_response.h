#ifndef START_INSTANCER_H
#define START_INSTANCER_H
#include <string>
#include <map>
#include "src/compute_api/include/model/instance_set.h"
using namespace std;
using namespace model;

namespace model
{
	class start_instances_response
	{
	private:
		string request_id;
		vector<model::instance_set> instances;

	public:
		start_instances_response(const string &xml_doc);
		start_instances_response(){}

		const string get_request_id()
		{
			return request_id;
		}
		const vector<model::instance_set> get_instances()
		{
			return instances;
		}

	};
}
#endif