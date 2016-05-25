#include <string>
using namespace std;

namespace model
{
	class instance_type
	{
	private:
		float vcpus;
		float ram;
		string id;
	public:
		instance_type(float vcpus_, float ram_, string id_)
		{
			vcpus = vcpus_;
			ram = ram_;
			id = id_;
		}
		instance_type(){}
		
		const float get_vcpus()
		{
			return vcpus;
		}

		const float get_ram()
		{
			return ram;
		}

		const string get_id()
		{
			return id;
		}
	};
}