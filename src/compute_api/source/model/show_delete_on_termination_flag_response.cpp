#include "src/compute_api/include/model/show_delete_on_termination_flag_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::show_delete_on_termination_flag_response::show_delete_on_termination_flag_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{
		if(Element->GetText())request_id = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else cout<<"Error Parsing request_id from XML show_delete_on_termination_flag_response\n";
	XMLElement *VolumeElement;
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)VolumeElement = Element->FirstChildElement("instanceId");
		if(VolumeElement!=NULL){
			instance_id = VolumeElement->GetText();
			VolumeElement=VolumeElement->NextSiblingElement();
		}
		else cout<< "Error Parsing instance_id from show_delete_on_termination_flag_response XML\n";
	}
	
	if(VolumeElement!=NULL)
	{
		if(VolumeElement->GetText()!=NULL)volume_id = VolumeElement->GetText();
		VolumeElement=VolumeElement->NextSiblingElement();
	}
	else cout<<"Error Parsing volume_id from XML show_delete_on_termination_flag_response\n";

	VolumeElement->QueryBoolText(&delete_on_termination);
}
