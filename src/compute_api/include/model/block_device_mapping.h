#ifndef BLOCK_DEVICE_MAPPING
#define BLOCK_DEVICE_MAPPING
using namespace std;
namespace model
{
	struct block_device_mapping
	{
		string device_name;
		bool delete_on_termination;
		int volume_size;
	};
}

#endif