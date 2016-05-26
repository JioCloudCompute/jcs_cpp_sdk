#include "src/compute_api/include/model/run_instances_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;



run_instances_response::run_instances_response(const string &xml_doc)
{	
	
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();
	Element = RootNode->FirstChildElement("instancesSet");
	bool temp;
	block_device_instance block;
	group_set group;
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *InstanceElement,*blockListElement,*blockElement;
	vector< group_set > groups;
	string vpc_id, dnsName, instance_id, instance_state,image_id,private_dns_name,key_name, launch_time, subnet_id, instance_type, private_ip_address;
	while(ListElement != NULL)
	{
		InstanceElement =  ListElement->FirstChildElement("vpcId");
		if(InstanceElement->GetText()!=NULL)vpc_id=InstanceElement->GetText();

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)dnsName=InstanceElement->GetText();
		
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)instance_id=InstanceElement->GetText();

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)instance_state=InstanceElement->GetText();

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)image_id=InstanceElement->GetText();

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)private_dns_name=InstanceElement->GetText();

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)key_name=InstanceElement->GetText();

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)launch_time=InstanceElement->GetText();

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)subnet_id=InstanceElement->GetText();

		XMLElement *GroupListElement,*GroupElement;
		InstanceElement = InstanceElement->NextSiblingElement();
		GroupListElement = InstanceElement->FirstChildElement("item");
		groups.clear();
		while(GroupListElement != NULL)
		{
			GroupElement=GroupListElement->FirstChildElement("groupName");
			group.group_name = GroupElement->GetText();
			GroupElement=GroupElement->NextSiblingElement();
			group.group_id = GroupElement->GetText();
			groups.push_back(group);
			GroupListElement=GroupListElement->NextSiblingElement();
		}
		
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)instance_type=(InstanceElement->GetText());
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)private_ip_address=(InstanceElement->GetText());

		ListElement=ListElement->NextSiblingElement();
		
		instance data(vpc_id,dnsName, instance_id, instance_state, image_id, private_dns_name, key_name, launch_time, subnet_id, groups, instance_type, private_ip_address);
		instances.push_back(data);

	}


}


