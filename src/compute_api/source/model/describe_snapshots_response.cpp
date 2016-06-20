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
#include "src/compute_api/include/model/describe_snapshots_response.hpp"
#include "src/XMLParser.h"
#include <string>
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::describe_snapshots_response::describe_snapshots_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{
		request_id = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing Request ID from XML describe_snapshots_response\n";
	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *SnapshotElement;
	string status, snapshot_id,  start_time, volume_id;
	float volume_size;
	while(ListElement != NULL)
	{
		SnapshotElement = ListElement->FirstChildElement("status");
		if(SnapshotElement!=NULL)
		{
			status = SnapshotElement->GetText();
			SnapshotElement = SnapshotElement->NextSiblingElement();
		}
		else cout<<"Error Parsing status from XML describe_snapshots_response\n";

		if(SnapshotElement!=NULL)
		{	
			snapshot_id = SnapshotElement->GetText();
			SnapshotElement=SnapshotElement->NextSiblingElement();
		}
		else cout<<"Error Parsing snapshot_id from XML describe_snapshots_response\n";

		if(SnapshotElement!=NULL)
		{
			SnapshotElement->QueryFloatText(&volume_size);
			SnapshotElement=SnapshotElement->NextSiblingElement();
		}
		else cout<<"Error Parsing volume_size from XML describe_snapshots_response\n";
		
		if(SnapshotElement!=NULL)
		{
			volume_id=SnapshotElement->GetText();
			SnapshotElement=SnapshotElement->NextSiblingElement();
		}
		else cout<<"Error Parsing volume_id from XML describe_snapshots_response\n";
		
		if(SnapshotElement!=NULL)
			if(SnapshotElement->GetText()!=NULL) start_time = SnapshotElement->GetText();
		else cout<<"Error Parsing start_time from XML describe_snapshots_response\n";
		//add to map
		model::snapshot data(status,snapshot_id,volume_size,volume_id,start_time);
		snapshot_set.push_back(data);
		ListElement=ListElement->NextSiblingElement();
	}

}
