#include "src/compute_api/include/model/delete_key_pair_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

model::delete_key_pair_response::delete_key_pair_response(const string &xml_doc)
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
	else cout<<"Error Parsing request_id from XML delete_key_pair_response\n";
	bool temp=false;
	if(Element!=NULL)
	Element->QueryBoolText(&temp);
	else cout<<"Error Parsing result from delete_key_pair_response XML\n";
	result = temp;

}

