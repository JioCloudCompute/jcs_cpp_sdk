#include "src/compute_api/include/model/describe_key_pair_response.h"
#include "src/XMLParser.h"
#include <iostream>
#include <string>


#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

model::describe_key_pair_response::describe_key_pair_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc);
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	requestId = Element->GetText();

	Element=Element->NextSiblingElement();
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *KeyPairElement;
	string keyname,keyfingerprint;
	while(ListElement != NULL)
	{	
		KeyPairElement = ListElement->FirstChildElement("keyName");
		keyname=KeyPairElement->GetText();
		
		KeyPairElement=KeyPairElement->NextSiblingElement();
		keyfingerprint=KeyPairElement->GetText();
		model::key_pair key(keyname,keyfingerprint);
		key_pairs[keyname]=key;
	}




}