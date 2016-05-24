#include "src/compute_api/include/model/show_delete_on_termination_flag_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::show_delete_on_termination_flag_response::show_delete_on_termination_flag_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc);
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();
	
	Element = Element->NextSiblingElement();
	XMLElement *VolumeElement = Element->FirstChildElement("instanceId");
	instance_id = VolumeElement->GetText();

	VolumeElement=VolumeElement->NextSiblingElement();
	volume_id = VolumeElement->GetText();

	VolumeElement=VolumeElement->NextSiblingElement();
	VolumeElement->QueryBoolText(&delete_on_termination);
}