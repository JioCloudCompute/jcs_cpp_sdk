#include "src/compute_api/include/model/reboot_instances_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::reboot_instances_response::reboot_instances_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{	
		if(Element->GetText()!=NULL)request_id = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else cout<<"Error Parsing request_id from XML reboot_instances_response\n";

	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *InstanceSetElement;
	string instance_id, current_state, previous_state; 
	
	while(ListElement != NULL)
	{
		InstanceSetElement = ListElement->FirstChildElement("instanceId");
		
		if(InstanceSetElement!=NULL)
		{
			instance_id = InstanceSetElement->GetText();
			InstanceSetElement=InstanceSetElement->NextSiblingElement();
		}
		else cout<<"Error Parsing instance_id from XML reboot_instances_response\n";
		
		if(InstanceSetElement!=NULL)
		{	
			if(InstanceSetElement->GetText()!=NULL) current_state = InstanceSetElement->GetText();
			InstanceSetElement=InstanceSetElement->NextSiblingElement();
		}
		else cout <<"Error Parsing current_state from XML reboot_instances_response\n";

		if(InstanceSetElement!=NULL)
		if(InstanceSetElement->GetText()!=NULL)previous_state = InstanceSetElement->GetText();

		//Add to the map;
		model::instance_set data(instance_id, current_state, previous_state);
		instances.push_back(data);
		
		ListElement=ListElement->NextSiblingElement();
	}
}
