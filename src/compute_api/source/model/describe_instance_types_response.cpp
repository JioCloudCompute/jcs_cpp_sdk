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
#include "model/describe_instance_types_response.hpp"
#include "XMLParser.h"
#include <string>
#include <iostream>
#include <utils.hpp>


using namespace std;
using namespace tinyxml2;
using namespace utils;

model::describe_instance_types_response::describe_instance_types_response(const string &xml_doc)
{
  XMLDocument doc;
  doc.Parse(xml_doc.c_str());
  //Root
  const XMLNode *RootNode = doc.FirstChild();
  if (RootNode) {
    set_string_value(RootNode, "requestId", request_id);
    const XMLElement* Element = RootNode->FirstChildElement("instanceTypes");	
    if (Element) {
      const XMLElement *InstanceTypeElement;
      const XMLElement *ListElement = Element->FirstChildElement("item");
      while(ListElement != NULL) {
        float vcpus,ram;
        string id;
        set_float_value(ListElement, "vcpus", vcpus);
        set_float_value(ListElement, "ram", ram);
        set_string_value(ListElement, "id", id);
        //Add to map
        model::instance_type data(vcpus, ram, id);
        instance_type_set.push_back(data);

        ListElement = ListElement->NextSiblingElement();
      }
    }
  }
}
