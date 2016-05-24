#include "src/compute_api/include/model/describe_snapshot_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::describe_snapshot_response::describe_snapshot_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc);
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element=Element->NextSiblingElement();
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *SnapshotElement;
	string status,
	while(ListElement != NULL)
	{
		SnapshotElement = ListElement->FirstChildElement("status");

	}

}