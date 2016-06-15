/*****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
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

	vector<group_set> groups;
	vector<block_device_instance> blocks;
	string vpc_id, dns_name, instance_id, instance_state,image_id,private_dns_name,key_name, launch_time, subnet_id, instance_type, private_ip_address;
	while(ListElement != NULL)
	{
		InstanceElement =  ListElement->FirstChildElement("blockDeviceMapping");
		blocks.clear();
		groups.clear();
		
		blockListElement = InstanceElement->FirstChildElement("item");
		while(blockListElement != NULL)
		{
			blockElement = blockListElement->FirstChildElement("status");
			if(blockElement->GetText()!=NULL)block.status = blockElement->GetText();
			
			blockElement = blockElement->NextSiblingElement();
			if(blockElement->GetText()!=NULL)block.device_name = blockElement->GetText();

			blockElement = blockElement->NextSiblingElement();
			blockElement->QueryBoolText(&temp);
			block.delete_on_termination = temp;

			blockElement = blockElement->NextSiblingElement();
			if(blockElement->GetText()!=NULL)block.volume_id = blockElement->GetText();

			blocks.push_back(block);
			blockListElement=blockListElement->NextSiblingElement();

		}

		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)dns_name=InstanceElement->GetText();
		
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
		if(InstanceElement->GetText()!=NULL)vpc_id=InstanceElement->GetText();
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)instance_type=InstanceElement->GetText();
		InstanceElement=InstanceElement->NextSiblingElement();
		if(InstanceElement->GetText()!=NULL)private_ip_address=InstanceElement->GetText();

		ListElement=ListElement->NextSiblingElement();
		
		instance data(blocks,dns_name, instance_id, instance_state, image_id, private_dns_name, key_name, launch_time, subnet_id, groups, vpc_id, instance_type, private_ip_address);
		instances.push_back(data);

	}

}
