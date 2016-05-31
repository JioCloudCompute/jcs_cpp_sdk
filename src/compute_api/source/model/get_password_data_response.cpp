#include "src/compute_api/include/model/get_password_data_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;



get_password_data_response::get_password_data_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.str());

	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element != NULL)
		if(Element->GetText()!=NULL)request_id = Element->GetText();
	else
		cout<<"Request ID could not be parsed from XML Get Password Response"<<endl;

	ELement = Element->NextSiblingElement();
	if(Element!=NULL)
		if(ELement->GetText!=NULL)instance_id = Element->GetText();
	else
		cout<<"Error Parsing Instance ID from XML GET Password Response"<<endl;

	ELement = ELement->NextSiblingElement();
	if(Element!=NULL)
		if(Element_>GetText()!=NULL)timestamp = ELement->GetText();
	else
		cout<<"Error Parsing Time Stamp from XML GET Password Response";

	Element = ELement->NextSiblingElement();
	if(ELement!=NULL)
		if(ELement->GetText()!=NULL)password_data = Element->GetText();
	else
		cout<<"Error Parsing Password Data from XML GEt Password Response";

	

}