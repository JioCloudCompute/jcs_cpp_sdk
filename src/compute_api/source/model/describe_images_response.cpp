/*****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
#include "src/compute_api/include/model/describe_images_response.hpp"
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
	
	//First Child;
	XMLElement *FirstElement = RootNode->FirstChildElement("requestId");
	
	if(FirstElement!=NULL)
	if(FirstElement->GetText()!=NULL)request_id = FirstElement->GetText();
	else cout<<"Error Parsing request_id from describe_images_response XML\n";
	//ImageSet
	XMLElement *SecondElement = RootNode->FirstChildElement("imagesSet");
	
	XMLElement *ListElement;
	if(SecondElement!=NULL)ListElement= SecondElement->FirstChildElement("item");
	
	//iterating over the list
	block_device block_device_mapping;
	XMLElement *ImageElement,*BlockElement;
	string name,image_id, image_state, architecture, image_type;
	while(ListElement != NULL )
	{	
		
		ImageElement = ListElement->FirstChildElement("blockDeviceMapping");
		//if(ImageElement == NULL) return XML_ERROR_PARSING_ELEMENT;

		//Set the block device
		if(ImageElement!=NULL)
		{
			BlockElement = ImageElement->FirstChildElement("deviceName");
			ImageElement = ImageElement->NextSiblingElement();
		}

		if(BlockElement!=NULL)
		{
			if(BlockElement->GetText()!=NULL)block_device_mapping.deviceName = BlockElement->GetText();
			BlockElement = BlockElement->NextSiblingElement();
		}
		else cout<<"Error Parsing Block Device Name from describe_images_response XML\n";

		if(BlockElement!=NULL)
		{
			if(BlockElement->GetText()!=NULL)block_device_mapping.deleteOnTermination = (bool)BlockElement->GetText();
			BlockElement = BlockElement->NextSiblingElement();
		}
		else cout<<"Error Parsing Block Device deleteOnTermination Flag from describe_images_response XML\n";
		if(BlockElement!=NULL)
		{
			if(BlockElement->GetText()!=NULL)BlockElement->QueryFloatText(&block_device_mapping.volumeSize);
			BlockElement = BlockElement->NextSiblingElement();
		}
		else cout<<"Error Parsing Block Device Volume Size from describe_images_response XML\n";

		if(BlockElement!=NULL)
			{if(BlockElement->GetText()!=NULL)block_device_mapping.snapshotId = BlockElement->GetText();}
		else cout<<"Error Parsing Block Device snapshotId from describe_images_response XML\n";
		

		if(ImageElement!=NULL)
		{
			if(ImageElement->GetText()!=NULL)name=ImageElement->GetText();
			ImageElement = ImageElement->NextSiblingElement();
		}
		else cout<<"Error Parsing Immage Name from describe_images_response XML\n";
		bool isPublic=false;
		
		if(ImageElement != NULL)
		{
			if(ImageElement->GetText()!=NULL)ImageElement->QueryBoolText(&isPublic);
			ImageElement = ImageElement->NextSiblingElement();
		}
		else cout<<"Error Parsing Is Public Flag from XML describe_images_response\n";
		if(ImageElement!=NULL)
		{
			if(ImageElement->GetText()!=NULL)image_id = (ImageElement->GetText());
			ImageElement = ImageElement->NextSiblingElement();
		}
		else cout<<"Error Parsing image id from describe_images_response XMl\n";
		if(ImageElement!=NULL)
		{
			if(ImageElement->GetText()!=NULL)image_state = (ImageElement->GetText());
			ImageElement = ImageElement->NextSiblingElement();
		}
		else cout<<"Error Parsing image State from describe_images_response XML\n";
		if(ImageElement!=NULL)
		{
			if(ImageElement->GetText()!=NULL)architecture = (ImageElement->GetText());
			ImageElement = ImageElement->NextSiblingElement();
		}
		else cout<<"Error Parsing Image architecture from describe_images_response XML\n";
		if(ImageElement!=NULL)
			{if(ImageElement->GetText()!=NULL)image_type = (ImageElement->GetText());}
		else cout<<"Error Parsing Image Type from describe_images_response XML\n";
		
		//constructor of Image Object
		image image_data(block_device_mapping, name, isPublic, image_id, image_state, architecture, image_type);
		images.push_back(image_data);

		ListElement=ListElement->NextSiblingElement();
	}

}
