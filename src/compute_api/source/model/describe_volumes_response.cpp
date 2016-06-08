#include "src/compute_api/include/model/describe_volumes_response.h"
#include "src/XMLParser.h"
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::describe_volumes_response::describe_volumes_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{	if(Element->GetText()!=NULL)request_id = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing request_id from XML describe_volumes_response\n";

	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *VolumeSet,*SubElement;
	string status,volume_id, device, instance_id, snapshot_id,create_time;
	float size;
	while(ListElement != NULL)
	{
		VolumeSet =  ListElement->FirstChildElement("status");
		if(VolumeSet!=NULL)
		{
			if(VolumeSet->GetText()!=NULL)status = VolumeSet->GetText();
			VolumeSet =VolumeSet->NextSiblingElement();
		}
		else cout<<"Error Parsing status from XML describe_volumes_response\n";
		if(VolumeSet!=NULL)
		{
			if(VolumeSet->GetText()!=NULL)volume_id = VolumeSet->GetText();
			VolumeSet = VolumeSet->NextSiblingElement();
		}
		else cout<<"Error Parsing volume_id from XML describe_volumes_response\n";
		
		if(VolumeSet!=NULL)
		{
			if(VolumeSet->GetText()!=NULL)
			{
				SubElement = (VolumeSet->FirstChildElement("item"))->FirstChildElement("device");
				if(SubElement!=NULL)
				{
					if(SubElement->GetText()!=NULL)device = SubElement->GetText();
					SubElement = SubElement->NextSiblingElement();
				}
				else cout<<"Error Parsing device Name from XML describe_volumes_response\n";

				if(SubElement!=NULL)
				if(SubElement->GetText()!=NULL)instance_id = SubElement->GetText();
			}
			VolumeSet=VolumeSet->NextSiblingElement();
		}
		if(VolumeSet!=NULL)
		{	
			if(VolumeSet->GetText()!=NULL)snapshot_id = VolumeSet->GetText();
			VolumeSet=VolumeSet->NextSiblingElement();
		}
		else cout<<"Error Parsing snapshot_id from XML describe_volumes_response\n";	
		if(VolumeSet!=NULL)
		{
			if(VolumeSet->GetText()!=NULL)create_time= VolumeSet->GetText();
			VolumeSet=VolumeSet->NextSiblingElement();
		}
		else cout<<"Error Parsing create_time from XML describe_volumes_response\n";
		
		if(VolumeSet!=NULL)
			{if(VolumeSet->GetText()!=NULL)VolumeSet->QueryFloatText(&size);}
		else cout<<"Error Parsing Volume Size from XML describe_volumes_response\n";

		model::volume data(status, volume_id, device, instance_id, snapshot_id, create_time, size);
		volume_set.push_back(data);

		ListElement=ListElement->NextSiblingElement();

	}

}
