#include <string.h>
using namespace std;
class block_device
{	
public:
	float volumeSize;
	bool deleteOnTermination;
	string deviceName;
	string snapshotId;
};