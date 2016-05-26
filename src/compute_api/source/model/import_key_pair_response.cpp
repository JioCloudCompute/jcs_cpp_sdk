#include "src/compute_api/include/model/import_key_pair_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

import_key_pair_response::import_key_pair_response(const string &xml_doc)
{	
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	string key_fingerprint, key_name;
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element=Element->NextSiblingElement();
	if(Element->GetText()!=NULL)key_name=Element->GetText();

	Element=Element->NextSiblingElement();
	if(Element->GetText()!=NULL)key_fingerprint=Element->GetText();

	key=key_pair(key_name,key_fingerprint);

}