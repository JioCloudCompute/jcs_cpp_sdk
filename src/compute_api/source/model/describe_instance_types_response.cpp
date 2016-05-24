#include "src/compute_api/include/model/update_delete_on_termination_flag_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::update_delete_on_termination_flag_response::update_delete_on_termination_flag_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc);
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element=Element->NextSiblingElment();
	XMLElement *InstanceTypeElement,*ListElement = Element->FirstChildElement("item");
	float vcpus,ram;
	string id;
	while(ListElement != NULL)
	{
		InstanceTypeElement = ListElement->FirstChildElement("vcpus");
		InstanceTypeElement->QueryFloatText(&vcpus);

		InstanceTypeElement = InstanceTypeElement->NextSiblingElment();
		InstanceTypeElement->QueryFloatText(&ram);

		InstanceTypeElement = InstanceTypeElement->NextSiblingElment();
		id = InstanceTypeElement->GetText();

		//Add to map
		model::instance_type data(vcpus, ram, id);
		instance_types_set[id] = data;
	}
}
