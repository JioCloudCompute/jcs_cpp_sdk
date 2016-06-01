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
	doc.Parse(xml_doc.c_str());

	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element != NULL)
		if(Element->GetText()!=NULL)request_id = Element->GetText();
	else
		cout<<"Request ID could not be parsed from XML Get Password Response\n"<<endl;

	Element = Element->NextSiblingElement();
	if(Element!=NULL)
		if(Element->GetText()!=NULL)instance_id = Element->GetText();
	else
		cout<<"Error Parsing Instance ID from XML GET Password Response\n"<<endl;

	Element = Element->NextSiblingElement();
	if(Element!=NULL)
		if(Element->GetText()!=NULL)timestamp = Element->GetText();
	else
		cout<<"Error Parsing Time Stamp from XML GET Password Response\n";

	Element = Element->NextSiblingElement();
	if(Element!=NULL)
		if(Element->GetText()!=NULL)password_data = Element->GetText();
	else
		cout<<"Error Parsing Password Data from XML GEt Password Response\n";

	

}