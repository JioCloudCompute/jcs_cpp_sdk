#ifndef BLOCK_DEVICE_INSTANCE_H
#define BLOCK_DEVICE_INSTANCE_H
#include <string>
using namespace std;
namespace model{

	class block_device_instance
	{
	public:
		string status;
		string device_name;
		bool delete_on_termination;
		string volume_id;
	};
}

#endif
