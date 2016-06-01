#include "src/compute_api/include/model/attach_volume_response.h"
#include "src/XMLParser.h"
#include <iostream>
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

attach_volume_response::attach_volume_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode=doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)request_id = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else
		cout<<"Error Parsing Request ID from XML Attach Volume Response\n";

	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)device = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else
		cout<<"Error Parsing device name from XML Attach Volume Response\n";

	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)instance_id = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else
		cout<<"Error Parsing instance id from XML Attach Volume Response\n";

	if(Element!=NULL)
	{
		Element->QueryBoolText(&delete_on_termination);
		Element = Element->NextSiblingElement();
	}
	else
		cout<< "Error Parsing Delete On Termination Flag from XML Attach Response\n";

	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)status = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else
		cout<< "Error Parsing Status from XML Attach Response\n";

	if(Element!=NULL)
		{if(Element->GetText()!=NULL)volume_id = Element->GetText();}
	else
		cout<<"Error Parsing Volume ID from XML ATTACH Response\n";
		
}
