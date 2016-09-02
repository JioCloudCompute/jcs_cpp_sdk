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
#include "model/run_instances_response.hpp"
#include "XMLParser.h"
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
	if(Element!=NULL)request_id = Element->GetText();
	Element = RootNode->FirstChildElement("instancesSet");
	
	block_device_instance block;
	group_set group;
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *InstanceElement;
	vector< group_set > groups;
	string vpc_id, dnsName, instance_id, instance_state,image_id,private_dns_name,key_name, launch_time, subnet_id, instance_type, private_ip_address;
	while(ListElement != NULL)
	{
		InstanceElement =  ListElement->FirstChildElement("vpcId");
		if(InstanceElement!=NULL)
		{
			if(InstanceElement->GetText()!=NULL)vpc_id=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error Parsing vpc_id from XML run_instances_response\n";
		if(InstanceElement!=NULL)
		{
			if(InstanceElement->GetText()!=NULL)dnsName=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error Parsing dnsName from XML run_instances_response\n";

		if(InstanceElement!=NULL)
		{	
			if(InstanceElement->GetText()!=NULL)instance_id=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error Parsing instance_id from XML run_instances_response\n";
		if(InstanceElement!=NULL)
		{
			if(InstanceElement->GetText()!=NULL)instance_state=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error Parsing instance_state from XML run_instances_response\n";
		if(InstanceElement!=NULL)
		{
			if(InstanceElement->GetText()!=NULL)image_id=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error Parsing image_id from XML run_instances_response\n";
		if(InstanceElement!=NULL)
		{	
			if(InstanceElement->GetText()!=NULL)private_dns_name=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error Parsing private_dns_name from XML run_instances_response\n";
		if(InstanceElement!=NULL)
		{
			if(InstanceElement->GetText()!=NULL)key_name=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error PArsing key_name from XML run_instances_response\n";
		if(InstanceElement !=NULL)
		{
			if(InstanceElement->GetText()!=NULL)launch_time=InstanceElement->GetText();
			InstanceElement=InstanceElement->NextSiblingElement();
		}
		else cout<<"Error parsing launch_time from XML run_instances_response\n";

		if(InstanceElement!=NULL)
		if(InstanceElement->GetText()!=NULL)subnet_id=InstanceElement->GetText();

		XMLElement *GroupListElement,*GroupElement;
		
		if(InstanceElement!=NULL)
		{	
			InstanceElement = InstanceElement->NextSiblingElement();
			GroupListElement = InstanceElement->FirstChildElement("item");
		}
		groups.clear();
		while(GroupListElement != NULL)
		{
			GroupElement=GroupListElement->FirstChildElement("groupName");
			if(GroupElement!=NULL)
			{	
				if(GroupElement->GetText()!=NULL)
				group.group_name = GroupElement->GetText();
				GroupElement=GroupElement->NextSiblingElement();
			}
			if(GroupElement!=NULL)
			{
				if(GroupElement->GetText()!=NULL)group.group_id = GroupElement->GetText();}
			else cout<<"Error Parsing Group Element Data from XML run_instances_response\n";
			
			groups.push_back(group);
			GroupListElement=GroupListElement->NextSiblingElement();
		}
		if(InstanceElement!=NULL)
		InstanceElement=InstanceElement->NextSiblingElement();
		
		if(InstanceElement!=NULL)
		{
			if(InstanceElement->GetText()!=NULL)instance_type=(InstanceElement->GetText());
			InstanceElement=InstanceElement->NextSiblingElement();	
		}
		else cout<<"Error Parsing instance_type from XML run_instances_response\n";
		
		if(InstanceElement!=NULL)
		if(InstanceElement->GetText()!=NULL)private_ip_address=(InstanceElement->GetText());

		ListElement=ListElement->NextSiblingElement();
		
		instance data(vpc_id,dnsName, instance_id, instance_state, image_id, private_dns_name, key_name, launch_time, subnet_id, groups, instance_type, private_ip_address);
		instances.push_back(data);

	}


}


