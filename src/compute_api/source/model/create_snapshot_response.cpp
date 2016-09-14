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
#include "model/create_snapshot_response.hpp"
#include "XMLParser.h"
#include <iostream>
#include <string>
#include <utils.hpp>


using namespace std;
using namespace tinyxml2;
using namespace model;
using namespace utils;

model::create_snapshot_response::create_snapshot_response(const string &xml_doc): encrypted(false), volume_size(0)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	const XMLNode *RootNode = doc.FirstChild();
  if (RootNode) {
    set_string_value(RootNode, "requestId", request_id);
    set_string_value(RootNode, "status", status);	
    set_string_value(RootNode, "snapshotId", snapshot_id);
    set_float_value(RootNode, "volumeSize", volume_size);
    set_string_value(RootNode, "volumeId", volume_id);
    set_string_value(RootNode, "startTime", start_time);
    set_bool_value(RootNode, "encrypted", encrypted);
  }
}
