#include "src/compute_api/include/model/create_volume_response.h"
#include "src/XMLParser.h"


#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::create_volume_response::create_volume_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc);
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element = Element->NextSiblingElement();
	status=Element->GetText();
	Element = Element->NextSiblingElement();
	volume_id = Element->GetText();

	Element=Element->NextSiblingElement();

	Element=Element->NextSiblingElement();
	snapshot_id = Element->GetText();

	Element=Element->NextSiblingElement();
	create_time = Element->GetText();

	Element=Element->NextSiblingElement();
	Element->QueryFloatText(&size);
}