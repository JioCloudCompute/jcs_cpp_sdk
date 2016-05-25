#include "src/compute_api/include/model/describe_volumes_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::describe_volumes_response::describe_volumes_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	request_id = Element->GetText();

	Element=Element->NextSiblingElement();

	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *VolumeSet,*SubElement;
	string status,volume_id, device, instance_id, snapshot_id,create_time;
	float size;
	while(ListElement != NULL)
	{
		VolumeSet =  ListElement->FirstChildElement("status");
		status = VolumeSet->GetText();

		VolumeSet =VolumeSet->NextSiblingElement();
		volume_id = VolumeSet->GetText();

		VolumeSet = VolumeSet->NextSiblingElement();
		SubElement = (VolumeSet->FirstChildElement("item"))->FirstChildElement("device");
		device = SubElement->GetText();
		SubElement = SubElement->NextSiblingElement();
		instance_id = SubElement->GetText();

		VolumeSet=VolumeSet->NextSiblingElement();
		snapshot_id = VolumeSet->GetText();

		VolumeSet=VolumeSet->NextSiblingElement();
		create_time= VolumeSet->GetText();

		VolumeSet=VolumeSet->NextSiblingElement();
		VolumeSet->QueryFloatText(&size);

		model::volume data(status, volume_id, device, instance_id, snapshot_id, create_time, size);
		volume_set[volume_id]= data;

		ListElement=ListElement->NextSiblingElement();

	}

}
