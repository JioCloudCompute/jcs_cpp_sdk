#include "src/compute_api/include/model/describe_key_pairs_response.h"
#include "src/XMLParser.h"
#include <iostream>
#include <string>


#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

model::describe_key_pairs_response::describe_key_pairs_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{
		request_id = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing request_id from XML describe_key_pairs_response\n";

	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *KeyPairElement;
	string keyname,keyfingerprint;
	while(ListElement != NULL)
	{	
		KeyPairElement = ListElement->FirstChildElement("keyName");
		if(KeyPairElement!=NULL)
		{
			if(KeyPairElement->GetText()!=NULL) keyname=KeyPairElement->GetText();
			KeyPairElement=KeyPairElement->NextSiblingElement();
		}
		else cout<<"Error Parsing keyname from XML describe_key_pairs_response\n";
		if(KeyPairElement!=NULL)
			{if(keyfingerprint->GetText()!=NULL)keyfingerprint=KeyPairElement->GetText();}
		else
			cout<<"Error Parsing keyfingerprint from XML describe_key_pairs_response\n";
		
		model::key_pair key(keyname,keyfingerprint);
		key_pairs.push_back(key);
		ListElement=ListElement->NextSiblingElement();
	}

}