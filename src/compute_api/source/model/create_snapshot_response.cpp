#include "src/compute_api/include/model/create_snapshot_response.h"
#include "src/XMLParser.h"
#include <iostream>
#include <string>


#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

model::create_snapshot_response::create_snapshot_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
		{
			if(Element->GetText()!=NULL)request_id = Element->GetText();
			Element=Element->NextSiblingElement();
		}
	else
		cout<<"Error Parsing request_id from XML Create Snapshot Response\n";

	
	if(Element != NULL)
		{
			if(Element->GetText()!=NULL)status = Element->GetText();
			Element=Element->NextSiblingElement();
		}
	else
		cout<<"Error Parsing Status from XML Create Snapshot Response\n";
	
	if(Element != NULL)
		{
			if(Element->GetText()!=NULL)snapshot_id = Element->GetText();
			Element=Element->NextSiblingElement();
		}
	else
		cout<<"Error Parsing Snapshot ID from XML Create Snapshot Response\n";
	
	if(Element!=NULL)
		{
			if(Element->GetText()!=NULL)Element->QueryFloatText(&volume_size);
			Element=Element->NextSiblingElement();
		}
	else
		cout<<"Error Parsing Volume Size from XML create_snapshot_response\n";

	
	if(Element!=NULL)
	{	
		if(Element->GetText()!=NULL)volume_id = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else 
		cout<<"Error Parsing Volume Id from XMl create_snapshot_response\n";
	
	if(Element!=NULL)
		if(Element->GetText()!=NULL)start_time = Element->GetText();	
	else
		cout<<"Error Parsing start_time from XML Create Snapshot Response\n";


}
