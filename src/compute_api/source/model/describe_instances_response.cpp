#include "src/compute_api/include/model/describe_instances_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;



describe_instances_response::describe_instances_response(const string &xml_doc)
{	
	number_of_instances=0;
	
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();
	Element = RootNode->FirstChildElement("instancesSet");

	bool temp;
	block_device_instance block;
	groupSet group;
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *InstanceElement,*blockListElement,*blockElement;
	while(ListElement != NULL)
	{
		InstanceElement =  ListElement->FirstChildElement("blockDeviceMapping");
		instance data;
		blockListElement = InstanceElement->FirstChildElement("item");
		while(blockListElement != NULL)
		{
			blockElement = blockListElement->FirstChildElement("status");
			block.status = blockElement->GetText();
			
			blockElement = blockElement->NextSiblingElement();
			block.deviceName = blockElement->GetText();

			blockElement = blockElement->NextSiblingElement();
			blockElement->QueryBoolText(&temp);
			block.deleteOnTermination = temp;

			blockElement = blockElement->NextSiblingElement();
			block.volumeId = blockElement->GetText();

			data.Add_blockDevice(block);
			blockListElement=blockListElement->NextSiblingElement();

		}

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_dnsName(InstanceElement->GetText());
		
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_instanceId(InstanceElement->GetText());

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_instanceState(InstanceElement->GetText());

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_imageId(InstanceElement->GetText());

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_privateDnsName(InstanceElement->GetText());

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_keyName(InstanceElement->GetText());

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_launchtime(InstanceElement->GetText());

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_subnetId(InstanceElement->GetText());

		XMLElement *GroupListElement,*GroupElement;
		InstanceElement = InstanceElement->NextSiblingElement();
		GroupListElement = InstanceElement->FirstChildElement("item");
		
		while(GroupListElement != NULL)
		{
			GroupElement=GroupListElement->FirstChildElement("groupName");
			group.groupName = GroupElement->GetText();
			GroupElement=GroupElement->NextSiblingElement();
			group.groupId = GroupElement->GetText();
			data.Add_group(group);
			GroupListElement=GroupListElement->NextSiblingElement();
		}
		
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_vpcId(InstanceElement->GetText());
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_instanceType(InstanceElement->GetText());
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)data.Set_privateIpAddress(InstanceElement->GetText());

		ListElement=ListElement->NextSiblingElement();
		Instances[data.Get_instanceId()]=data;
		number_of_instances++;

	}


}
