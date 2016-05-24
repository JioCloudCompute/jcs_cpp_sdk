#include "src/compute_api/include/model/delete_key_pair_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

model::delete_key_pair_response::delete_key_pair_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc);
	//Root
	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildELement("requestId");
	request_id = Element->GetText();
	
	Element->NextSiblingElement();
	bool temp=false;
	Element->QueryBoolText(&temp);
	result = temp;

}
