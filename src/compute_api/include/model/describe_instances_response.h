#include "block_device.h"
#include <string>
#include <map>
using namespace std;
using namespace model;
namespace model{

	class describe_instances_response{
	private:
		
		map <string,block_device_instance> blockDevices;
		string requestId;
		string dnsName;
		string instanceId;
		string instanceState;  //STATE definition
		string imageId;
		string privateDnsName;
		string keyName;

		string launchtime;
		string subnetId;
		vector< groupSet > group;
		string vpcId;
		string instanceType;
		string privateIpAddress;
	public:
		describe_instances_response(const string xml_doc);
		void Add_blockDevice(const block_device_instance &data)
		{
			blockDevices[data.volumeId]=data;
		}
		void Set_requestId(string requestId)
		{
			this->requestId = requestId;
		}
		void Set_dnsName(string dnsName)
		{
			this->dnsName = dnsName;
		}
		void Set_instanceId(string instanceId)
		{
			this->instanceId = instanceId;
		}
		void Set_instanceState(string instanceState)
		{
			this->instanceState = instanceState;
		}
		void Set_imageId(string imageId)
		{
			this->imageId = imageId;
		}

		void Set_privateDnsName(string privateDnsName)
		{
			this->privatednsName = privatednsName;
		}
		void Set_keyName(string keyName)
		{
			this->keyName=keyName;
		}
		void Set_launchtime(string launchtime)
		{
			this->launchtime = launchtime;
		}
		void Set_subnetId(string subnetId)
		{
			this->subnetId = subnetId;
		}
		void Add_group(model::groupSet &data)
		{
			group.push_back(data);
		}
		void Set_vpcId(string vpcId)
		{
			this->vpcId=vpcId;
		}
		void Set_instanceType(string instanceType)
		{
			this->instanceType=instanceType;
		}
		void Set_privateIpAddress(string privateIpAddress)
		{
			this->privateIpAddress=privateIpAddress;
		}

		map<string,block_device_instance> Add_blockDevice() const
		{
			return blockDevices;
		}
		string Add_requestId() const
		{
			return requestId;
		}
		string Get_dnsName() const
		{
			return dnsName;
		}
		string Get_instanceId() const
		{
			return instanceId;
		}
		string Get_instanceState() const
		{
			return instanceState;
		}
		string Get_imageId() const
		{
			return imageId;
		}

		string Get_privateDnsName() const
		{
			return privatednsName;
		}
		string Get_keyName() const
		{
			return keyName;
		}
		string Get_launchtime() const
		{
			return launchtime;
		}
		string Get_subnetId() const
		{
			return subnetId;
		}
		vector<groupSet> Get_group() const
		{
			return group;
		}
		string Get_vpcId() const
		{
			return vpcId;
		}
		string Get_instanceType() const
		{
			return instanceType;
		}
		string Get_privateIpAddress() const
		{
			return privateIpAddress;
		}

	};




}