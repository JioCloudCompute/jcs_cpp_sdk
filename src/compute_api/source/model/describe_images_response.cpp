#include "src/compute_api/include/model/describe_images_response.h"
#include "src/XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

describe_images_response::describe_images_response(const string xml_doc)
{	
	image_number = 0;
	//XML Parse
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	//if (RootNode == NULL ) return XML_ERROR_PARSING_ELEMENT;
	
	//First Child;
	XMLElement *FirstElement = RootNode->FirstChildElement("requestId");
	//if(FirstElement == NULL) return XML_ERROR_PARSING_ELEMENT;

	Set_Request_Id(FirstElement->GetText());

	//ImageSet
	XMLElement *SecondElement = RootNode->FirstChildElement("imagesSet");
	//if(SecondElement == NULL)return XML_ERROR_PARSING_ELEMENT;
	
	XMLElement *ListElement = SecondElement->FirstChildElement("item");
	//if(ListElement == NULL)return XML_ERROR_PARSING_ELEMENT;

	//iterating over the list
	Image image_data;
	block_device block_device_mapping;
	XMLElement *ImageElement,*BlockElement;
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
		image_data.Set_block_device(block_device_mapping);

		//
		ImageElement = ImageElement->NextSiblingElement();
		image_data.Set_name(ImageElement->GetText());
		
		ImageElement = ImageElement->NextSiblingElement();
		bool isPublic;
		ImageElement->QueryBoolText(&isPublic);
		image_data.Set_isPublic(isPublic);
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.Set_imageId(ImageElement->GetText());
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.Set_imageState(ImageElement->GetText());
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.Set_architecture(ImageElement->GetText());
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.Set_imageType(ImageElement->GetText());
		
		Add_Image(image_data);
		Increment();
		
		ListElement=ListElement->NextSiblingElement();
	}

}