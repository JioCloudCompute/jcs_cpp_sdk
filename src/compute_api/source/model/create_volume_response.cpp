#include "src/compute_api/include/model/create_volume_response.h"
#include "src/XMLParser.h"


#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::create_volume_response::create_volume_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)request_id = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else
		cout<<"Error Parsing request_id from XML create_volume_response\n";
	
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)status=Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else
		cout<<"Error Parsing status from XML create_volume_response\n";

	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)volume_id = Element->GetText();
		Element = Element->NextSiblingElement();
		Element = Element->NextSiblingElement();
	}
	else
		cout<<"Error Parsing volume_id from XML create_volume_response\n";
	if(Element!= NULL)
	{
		if(Element->GetText()!=NULL)snapshot_id = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing snapshot_id from create_volume_response XML\n";
	if(Element!=NULL)
	{	
		if(Element->GetText()!=NULL)create_time = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing create_time data from create_volume_response XML\n";
	if(Element!=NULL)Element->QueryFloatText(&size);
	else cout<<"Error Parsing Size data from create_volume_response XML\n";
}
