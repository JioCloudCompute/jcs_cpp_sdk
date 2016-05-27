#ifndef BLOCK_DEVICE_H
#define BLOCK_DEVICE_H
#include <string.h>
using namespace std;
namespace model{
/// Class Describing Block Device 	
class block_device
{	
public:
	float volumeSize; ///< Volume Size of the Block Device
	bool deleteOnTermination;///< If true Block is deleted on Termination of Instance
	string deviceName;///< Device Name of the Volume
	string snapshotId;///< Snapshot ID of the snapshot to which the Volume begins
};

}

#endif
