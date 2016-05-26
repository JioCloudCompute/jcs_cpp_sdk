#include "src/compute_api/include/model/describe_images_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

describe_images_response::describe_images_response(const string &xml_doc)
{	
	//XML Parse
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	//if (RootNode == NULL ) return XML_ERROR_PARSING_ELEMENT;
	
	//First Child;
	XMLElement *FirstElement = RootNode->FirstChildElement("requestId");
	//if(FirstElement == NULL) return XML_ERROR_PARSING_ELEMENT;

	request_id = FirstElement->GetText();

	//ImageSet
	XMLElement *SecondElement = RootNode->FirstChildElement("imagesSet");
	//if(SecondElement == NULL)return XML_ERROR_PARSING_ELEMENT;
	
	XMLElement *ListElement = SecondElement->FirstChildElement("item");
	//if(ListElement == NULL)return XML_ERROR_PARSING_ELEMENT;

	//iterating over the list
	block_device block_device_mapping;
	XMLElement *ImageElement,*BlockElement;
	string name,image_id, image_state, architecture, image_type;
	while(ListElement != NULL )
	{	
		
		ImageElement = ListElement->FirstChildElement("blockDeviceMapping");
		//if(ImageElement == NULL) return XML_ERROR_PARSING_ELEMENT;

		//Set the block device
		BlockElement = ImageElement->FirstChildElement("deviceName");
		block_device_mapping.deviceName = BlockElement->GetText();
		BlockElement = BlockElement->NextSiblingElement();
		block_device_mapping.deleteOnTermination = (bool)BlockElement->GetText();
		BlockElement = BlockElement->NextSiblingElement();
		BlockElement->QueryFloatText(&block_device_mapping.volumeSize);
		BlockElement = BlockElement->NextSiblingElement();
		block_device_mapping.snapshotId = BlockElement->GetText();
		

		//
		ImageElement = ImageElement->NextSiblingElement();
		if(ImageElement->GetText()!=NULL)name=ImageElement->GetText();
		
		ImageElement = ImageElement->NextSiblingElement();
		bool isPublic;
		if(ImageElement->GetText()!=NULL)ImageElement->QueryBoolText(&isPublic);
		
		ImageElement = ImageElement->NextSiblingElement();
		if(ImageElement->GetText()!=NULL)image_id = (ImageElement->GetText());
		
		ImageElement = ImageElement->NextSiblingElement();
		if(ImageElement->GetText()!=NULL)image_state = (ImageElement->GetText());
		
		ImageElement = ImageElement->NextSiblingElement();
		if(ImageElement->GetText()!=NULL)architecture = (ImageElement->GetText());
		
		ImageElement = ImageElement->NextSiblingElement();
		if(ImageElement->GetText()!=NULL)image_type = (ImageElement->GetText());
		
		image image_data(block_device_mapping, name, isPublic, image_id, image_state, architecture, image_type);
		images.push_back(image_data);

		ListElement=ListElement->NextSiblingElement();
	}

}
