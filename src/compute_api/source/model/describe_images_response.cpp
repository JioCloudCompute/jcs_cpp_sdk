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
#include "model/describe_images_response.hpp"
#include "XMLParser.h"
#include <iostream>
#include "utils.hpp"

using namespace std;
using namespace tinyxml2;
using namespace model;
using namespace utils;

void parse_block_device_mapping(const XMLElement * list_element, block_device& block_device_mapping)
{
		const XMLElement* ImageElement = list_element->FirstChildElement("blockDeviceMapping");
    //Set the block device
    if(ImageElement)
    {
      set_string_value(ImageElement, "deviceName", block_device_mapping.deviceName);

      set_bool_value(ImageElement, "deleteOnTermination", block_device_mapping.deleteOnTermination);

      set_float_value(ImageElement, "volumeSize", block_device_mapping.volumeSize);

      set_string_value(ImageElement, "snapshotId", block_device_mapping.snapshotId);

    }
}

describe_images_response::describe_images_response(const string &xml_doc)
{	
	//XML Parse
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	const XMLNode *RootNode = doc.FirstChild();
	
	//First Child;
  set_string_value(RootNode, "requestId", request_id);

	//ImageSet
	const XMLElement *SecondElement = RootNode->FirstChildElement("imagesSet");
	
  if(SecondElement) {
    const XMLElement* ListElement= SecondElement->FirstChildElement("item");

    //iterating over the list
    while(ListElement)
    {
      string name,image_id, image_state, architecture, image_type;
      block_device block_device_mapping;
      bool isPublic=false;
      parse_block_device_mapping(ListElement, block_device_mapping);
      set_string_value(ListElement, "name", name);
      set_bool_value(ListElement, "isPublic", isPublic);
      set_string_value(ListElement, "imageId", image_id);
      set_string_value(ListElement, "imageState", image_state);
      set_string_value(ListElement, "architecture", architecture);
      set_string_value(ListElement, "imageType", image_type);		
      //constructor of Image Object
      image image_data(block_device_mapping, name, isPublic, image_id, image_state, architecture, image_type);
      images.push_back(image_data);

      ListElement=ListElement->NextSiblingElement();
    }
  }
}

