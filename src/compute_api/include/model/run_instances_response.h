#ifndef RUN_INSTANCESR_H
#define RUN_INSTANCESR_H
#include <string>
#include <map>
#include <src/compute_api/include/model/instance.h>

using namespace std;
using namespace model;
namespace model
{

	class run_instances_response{
	private:
		vector<instance> instances;
		string request_id;
	public:
		run_instances_response(const string &xml_doc);

		const string get_request_id()
		{
			return request_id;
		}

		const vector<instance> get_instances()
		{
			return instances;
		}

	};

}
#endif

