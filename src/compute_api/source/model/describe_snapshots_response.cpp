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
#include "model/describe_snapshots_response.hpp"
#include "XMLParser.h"
#include <string>
#include <iostream>
#include <utils.hpp>


using namespace std;
using namespace tinyxml2;
using namespace utils;

model::describe_snapshots_response::describe_snapshots_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	const XMLNode *RootNode = doc.FirstChild();
  if (RootNode) {
    set_string_value(RootNode, "requestId", request_id);
    const XMLElement * items = RootNode->FirstChildElement("snapshotSet");
    if (items) {
      const XMLElement *ListElement = items->FirstChildElement("item");
      while(ListElement != NULL)
      {
        string status, snapshot_id,  start_time, volume_id;
        bool encrypted(false);
        unsigned volume_size(0);
        set_string_value(ListElement, "status", status);
        set_string_value(ListElement, "snapshotId", snapshot_id);
        set_unsigned_value(ListElement, "volumeSize", volume_size);
        set_string_value(ListElement, "volumeId", volume_id);
        set_string_value(ListElement, "startTime", start_time);
        set_bool_value(ListElement, "encrypted", encrypted);
        model::snapshot data(status,snapshot_id,volume_size,volume_id,start_time, encrypted);
        snapshot_set.push_back(data);
        ListElement=ListElement->NextSiblingElement();
      }
    }
  }

}
