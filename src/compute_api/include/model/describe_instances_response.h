#ifndef DESCRIBE_INSTANCESR_H
#define DESCRIBE_INSTANCESR_H
#include <string>
#include <map>
#include <src/compute_api/include/model/instance.h>

using namespace std;
using namespace model;
namespace model
{

	class describe_instances_response{
	private:
		map<string, instance> instances;
		int number_of_instances;
		string request_id;
	public:
		describe_instances_response(const string &xml_doc);
		describe_instances_response(){}

		string get_request_id() const
		{
			return request_id;
		}

		map<string, instance> get_instances() const
		{
			return instances;
		}
		

	};



}
#endif

