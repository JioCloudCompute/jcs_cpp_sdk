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
		map<string, instance> Instances;
		int NumberOfInstances;
		string requestId;
	public:
		describe_instances_response(const string &xml_doc);
		Increment()
		{
			NumberOfInstances++;
		}
		Add_Instance(instance &data)
		{
			Instances[data.Get_instanceId()]=data;
		}
		void Set_requestId(string requestId)
		{
			this->requestId = requestId;
		}

		string Add_requestId() const
		{
			return requestId;
		}
		

	};



}
#endif

