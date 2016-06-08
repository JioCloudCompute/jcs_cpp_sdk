#include "src/compute_api/include/model/terminate_instances_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::terminate_instances_response::terminate_instances_response(const string &xml_doc)
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
	else cout<<"Error Parsing request_id from XML terminate_instances_response";

	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *InstanceSetElement;
	string instance_id, current_state, previous_state; 
	while(ListElement != NULL)
	{
		InstanceSetElement = ListElement->FirstChildElement("instanceId");
		
		if(InstanceSetElement!=NULL)
		{	
			if(InstanceSetElement->GetText()!=NULL)instance_id = InstanceSetElement->GetText();
			InstanceSetElement=InstanceSetElement->NextSiblingElement();
		}
		else cout<<"Error Parsing instance_id from XML terminate_instances_response";
		if(InstanceSetElement!=NULL)
		{
			if(InstanceSetElement->GetText()!=NULL)current_state = InstanceSetElement->GetText();
			InstanceSetElement=InstanceSetElement->NextSiblingElement();
		}
		else cout<<"Error Parsing current_state from XML terminate_instances_response";
		
		if(InstanceSetElement!=NULL & InstanceSetElement->GetText()!=NULL)
		previous_state = InstanceSetElement->GetText();
		else cout<<"Error Parsing previous_state from XML terminate_instances_response";

		//Add to the map;
		model::instance_set data(instance_id, current_state, previous_state);
		instances.push_back(data);
		
		ListElement=ListElement->NextSiblingElement();
	}
}
