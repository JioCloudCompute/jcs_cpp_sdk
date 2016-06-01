#include "src/compute_api/include/model/update_delete_on_termination_flag_response.h"
#include "src/XMLParser.h"
#include <string>
#include <iostream>
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::update_delete_on_termination_flag_response::update_delete_on_termination_flag_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
		if(Element->GetText()!=NULL)request_id = Element->GetText();
		Element = Element->NextSiblingElement();
	
	XMLElement *VolumeElement = Element->FirstChildElement("instanceId");
	
	if(VolumeElement!=NULL)
	{
		if(VolumeElement->GetText()!=NULL)instance_id = VolumeElement->GetText();
		VolumeElement=VolumeElement->NextSiblingElement();
	}
	else cout<<"Error Parsing instance_id from XML update_delete_on_termination_flag_response\n";
	if(VolumeElement!=NULL)
		{
			volume_id = VolumeElement->GetText();
			VolumeElement=VolumeElement->NextSiblingElement();
		}
	else
		cout<<"Erro Parsing volume_id from XML update_delete_on_termination_flag_response\n";
	if(VolumeElement!=NULL)
		VolumeElement->QueryBoolText(&delete_on_termination);
	else cout<<"Error Parsing delete_on_termination from XML update_delete_on_termination_flag_response\n";
}
