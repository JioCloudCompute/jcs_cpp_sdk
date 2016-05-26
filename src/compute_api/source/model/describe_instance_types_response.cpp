#include "src/compute_api/include/model/describe_instance_types_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::describe_instance_types_response::describe_instance_types_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element=Element->NextSiblingElement();
	XMLElement *InstanceTypeElement,*ListElement = Element->FirstChildElement("item");
	float vcpus,ram;
	string id;
	while(ListElement != NULL)
	{
		InstanceTypeElement = ListElement->FirstChildElement("vcpus");
		InstanceTypeElement->QueryFloatText(&vcpus);

		InstanceTypeElement = InstanceTypeElement->NextSiblingElement();
		InstanceTypeElement->QueryFloatText(&ram);

		InstanceTypeElement = InstanceTypeElement->NextSiblingElement();
		if(InstanceTypeElement->GetText() != NULL)id = InstanceTypeElement->GetText();

		//Add to map
		model::instance_type data(vcpus, ram, id);
		instance_type_set.push_back(data);

		ListElement=ListElement->NextSiblingElement();
	}
}
