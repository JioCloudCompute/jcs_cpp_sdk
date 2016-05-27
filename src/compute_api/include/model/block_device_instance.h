#ifndef BLOCK_DEVICE_INSTANCE_H
#define BLOCK_DEVICE_INSTANCE_H
#include <string>
using namespace std;
namespace model{
	/// Description Of Volume/Block Device
	class block_device_instance
	{
	public:
		string status; ///< Current Status of the Volume 
		string device_name;///< Device Name of the Volume
		bool delete_on_termination;///< If true Block is deleted on Termination of Instance
		string volume_id;///< Volume ID of the volume being described
	};
}

#endif
