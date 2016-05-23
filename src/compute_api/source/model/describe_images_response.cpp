#include "../../../include/model/describe_images_response.h"
#include "../../../XMLParser.h"
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

describe_images_response::describe_images_response(const string xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = xml_doc.FirstChild();
	if (RootNode == nullptr ) return XML_ERROR_PARSING_ELEMENT;
	//First Child;
	XMLElement *FirstElement = RootNode->FirstChildElement("requestId");
	if(FirstElement == nullptr) return XML_ERROR_PARSING_ELEMENT;

	Set_Request_Id(FirstElement->GetText());

	//ImageSet
	XMLElement *SecondElement = RootNode->FirstChildElement("imageset");
	if(SecondElement == nullptr)return XML_ERROR_PARSING_ELEMENT;
	
	XMLElement *ListElement = SecondElement->FirstChildElement("item");
	if(ListElement == nullptr)return XML_ERROR_PARSING_ELEMENT;

	//iterating over the list
	Image image_data;
	XMLElement *ImageElement,*BlockElement;
	while(ListElement != nullptr)
	{	
		ImageElement = ListElement->FirstChildElement("blockDeviceMapping");
		if(ImageElement == nullptr) return XML_ERROR_PARSING_ELEMENT;

		BlockElement = ImageElement->FirstChildElement("deviceName");
		image_data.block_device_mapping.deviceName = BlockElement->GetText();
		BlockElement = BlockElement->NextSiblingElement();
		image_data.block_device_mapping.deleteOnTermination = (bool)BlockElement->GetText();
		BlockElement = BlockElement->NextSiblingElement();
		BlockElement->QueryFloatText(&image_data.block_device_mapping.volumeSize);
		BlockElement = BlockElement->NextSiblingElement();
		image_data.block_device_mapping.snapshotId = BlockElement->GetText();

		ImageElement = ImageElement->NextSiblingElement();
		image_data.name = ImageElement->GetText();
		
		ImageElement = ImageElement->NextSiblingElement();
		ImageElement->QueryBoolText(&image_data.isPublic);
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.imageId = ImageElement->GetText();
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.imageState = ImageElement->GetText();
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.architecture = ImageElement->GetText();
		
		ImageElement = ImageElement->NextSiblingElement();
		image_data.imageType = ImageElement->GetText();
		
		Add_Image(image_data);

		ListElement->NextSiblingElement();
	}

}