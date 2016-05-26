#include "src/compute_api/include/model/stop_instances_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::stop_instances_response::stop_instances_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element = Element->NextSiblingElement();
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *InstanceSetElement;
	string instance_id, current_state, previous_state; 
	while(ListElement != NULL)
	{
		InstanceSetElement = ListElement->FirstChildElement("instanceId");
		instance_id = InstanceSetElement->GetText();

		InstanceSetElement=InstanceSetElement->NextSiblingElement();
		current_state = InstanceSetElement->GetText();

		InstanceSetElement=InstanceSetElement->NextSiblingElement();
		previous_state = InstanceSetElement->GetText();
		//Add to the map
		model::instance_set data(instance_id, current_state, previous_state);
		instances.push_back(data);
		
		ListElement=ListElement->NextSiblingElement();
	}
}
