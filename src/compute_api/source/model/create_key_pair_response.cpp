#include "src/compute_api/include/model/create_key_pair_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResu31
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

model::create_key_pair_response::create_key_pair_response(const string &xml_doc)
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
	else cout<<"Error Parsing Request Id from XML Create Key Pair Response\n";
	
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)key_material = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else
		cout<<"Error Parsing key_material from XML Create Key Pair Response\n";
	
	key_material.erase(key_material.begin(), key_material.begin()+31);
	key_material.erase(key_material.end()-31,key_material.end());
	
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)key_name = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing key name from XML Create Key Pair Response\n";
	
	if(Element!=NULL)
		if(Element->GetText()!=NULL)key_fingerprint = Element->GetText();
	else
		cout<<"Error Parsing Key FingerPrint from XML Create Key Pair Response\n";

}
