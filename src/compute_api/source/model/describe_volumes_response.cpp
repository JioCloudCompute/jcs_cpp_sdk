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
#include "model/describe_volumes_response.hpp"
#include "XMLParser.h"
#include <string>
#include <iostream>
#include <utils.hpp>

using namespace std;
using namespace tinyxml2;
using namespace utils;

model::describe_volumes_response::describe_volumes_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	const XMLNode *RootNode = doc.FirstChild();
  if (RootNode) {
    set_string_value(RootNode, "requestId", request_id);
    const XMLElement * Element = RootNode->FirstChildElement("volumeSet");
    const XMLElement * ListElement = NULL;
    if (Element)
      ListElement = Element->FirstChildElement("item");
    while(ListElement != NULL)
    {
      string status,volume_id, device, instance_id, snapshot_id,create_time;
      bool encrypted = false;
      string volume_type;
      float size;

      set_string_value(ListElement, "status", status);
      set_string_value(ListElement, "volumeId", volume_id);
      //Attachment set
      const XMLElement* attachment = ListElement->FirstChildElement("attachmentSet");
      if (attachment) {
        const XMLElement* items = attachment->FirstChildElement("item");
        if (items) {
          set_string_value(items, "device", device);
          set_string_value(items, "instanceId", instance_id);
        }
      }
      set_string_value(ListElement, "snapshotId", snapshot_id);
      set_string_value(ListElement, "createTime", create_time);
      set_float_value(ListElement, "size", size);
      set_bool_value(ListElement, "encrypted", encrypted);

      model::volume data(status, volume_id, device, instance_id, snapshot_id, create_time, size, encrypted, volume_type);
      volume_set.push_back(data);

      ListElement=ListElement->NextSiblingElement();

    }
  }
}
