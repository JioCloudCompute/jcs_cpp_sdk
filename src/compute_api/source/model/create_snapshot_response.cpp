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

model::create_snapshot_response::create_snapshot_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element=Element->NextSiblingElement();
	status = Element->GetText();

	Element=Element->NextSiblingElement();
	snapshot_id = Element->GetText();

	Element=Element->NextSiblingElement();
	Element->QueryFloatText(&volume_size);

	Element=Element->NextSiblingElement();
	volume_id = Element->GetText();

	Element=Element->NextSiblingElement();
	start_time = Element->GetText();


}
