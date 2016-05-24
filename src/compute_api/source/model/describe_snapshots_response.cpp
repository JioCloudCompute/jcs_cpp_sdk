#include "src/compute_api/include/model/describe_snapshots_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::describe_snapshots_response::describe_snapshots_response(const string xml_doc)
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
	string status, snapshot_id,  start_time, volume_id;
	float volume_size;
	while(ListElement != NULL)
	{
		SnapshotElement = ListElement->FirstChildElement("status");
		status = SnapshotElement->GetText();
		
		SnapshotElement = SnapshotElement->NextSiblingElement();
		snapshot_id = SnapshotElement->GetText();

		SnapshotElement=SnapshotElement->NextSiblingElement();
		SnapshotElement->QueryFloatText(&volume_size);

		SnapshotElement=SnapshotElement->NextSiblingElement();
		volume_id=SnapshotElement->GetText();

		SnapshotElement=SnapshotElement->NextSiblingElement();
		start_time = SnapshotElement->GetText();

		//add to map
		model::snapshot data(status,snapshot_id,volume_size,volume_id,start_time);
		snapshot_set[snapshot_id] = data;
		ListElement=ListElement->NextSiblingElement();
	}

}