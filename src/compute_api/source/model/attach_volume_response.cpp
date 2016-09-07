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

#include "model/attach_volume_response.hpp"
#include "XMLParser.h"
#include <iostream>
#include <utils.hpp>

using namespace std;
using namespace tinyxml2;
using namespace model;
using namespace utils;

attach_volume_response::attach_volume_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
  const XMLNode *RootNode=doc.FirstChild();
  if (RootNode) {
    set_string_value(RootNode, "requestId", request_id);
    set_bool_value(RootNode, "deleteOnTermination", delete_on_termination);
    set_string_value(RootNode, "device", device);
    set_string_value(RootNode, "instanceId", instance_id);
    set_string_value(RootNode, "status", status);
    set_string_value(RootNode, "volumeId", volume_id);
  }
}
