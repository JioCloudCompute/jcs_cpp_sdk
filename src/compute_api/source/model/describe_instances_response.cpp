#include "src/compute_api/include/model/describe_instances_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

describe_instances_response::describe_instances_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	Set_requestId(FirstElement->GetText());
	Element = RootNode->FirstChildElement("instancesSet");

	bool temp;
	block_device_instance block;
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *InstanceElement,*blockListElement,*blockElement;
	while(ListElement != NULL)
	{
		InstanceElement =  ListElement->FirstChildElement("blcokDeviceMapping");

		blockElement = InstanceElement->FirstChildElement("item");
		while(blockListElement != NULL)
		{
			blockElement = FirstChildElement("status");
			block.status = blockElement->GetText();
			
			blockElement = blockElement->NextSiblingElement();
			block.deviceName = blockElement->GetText();

			blockElement = blockElement->NextSiblingElement();
			blockElement->QueryBoolText(&temp);
			block.deleteOnTermination = temp;

			blockElement = blockElement->NextSiblingElement();
			block.volumeId = blockElement->GetText();

			Add_blockDevice(block);


		}

		///
	}


}