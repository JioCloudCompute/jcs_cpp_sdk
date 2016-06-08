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
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL) request_id = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing request_id from XML describe_instance_types_response\n";
	
	XMLElement *InstanceTypeElement,*ListElement = Element->FirstChildElement("item");
	float vcpus,ram;
	string id;
	while(ListElement != NULL)
	{
		InstanceTypeElement = ListElement->FirstChildElement("vcpus");
		if(InstanceTypeElement!=NULL)
		{
			InstanceTypeElement->QueryFloatText(&vcpus);
			InstanceTypeElement = InstanceTypeElement->NextSiblingElement();
		}
		else cout<<"Error Parsing VCPUS from XML describe_instance_types_response\n";
		if(InstanceTypeElement!=NULL)
		{	
			InstanceTypeElement->QueryFloatText(&ram);
			InstanceTypeElement = InstanceTypeElement->NextSiblingElement();
		}
		else cout<<"Error Parsing RAM data from XML describe_instance_types_response\n";

		if(InstanceTypeElement!=NULL)
			{if(InstanceTypeElement->GetText() != NULL)id = InstanceTypeElement->GetText();}
		else cout<<"Error Parsing instance_id from XML describe_instance_types_response\n";
		//Add to map
		model::instance_type data(vcpus, ram, id);
		instance_type_set.push_back(data);

		ListElement=ListElement->NextSiblingElement();
	}
}
