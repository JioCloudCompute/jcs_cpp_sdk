#ifndef BLOCK_DEVICE_H
#define BLOCK_DEVICE_H
#include <string.h>
using namespace std;
namespace model{
class block_device
{	
public:
	float volumeSize;
	bool deleteOnTermination;
	string deviceName;
	string snapshotId;
};

}

#endif
