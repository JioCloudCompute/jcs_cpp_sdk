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
#include "model/update_delete_on_termination_flag_response.hpp"
#include "XMLParser.h"
#include <string>
#include <iostream>
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::update_delete_on_termination_flag_response::update_delete_on_termination_flag_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
		if(Element->GetText()!=NULL)request_id = Element->GetText();
		Element = Element->NextSiblingElement();
	
	XMLElement *VolumeElement = Element->FirstChildElement("instanceId");
	
	if(VolumeElement!=NULL)
	{
		if(VolumeElement->GetText()!=NULL)instance_id = VolumeElement->GetText();
		VolumeElement=VolumeElement->NextSiblingElement();
	}
	else cout<<"Error Parsing instance_id from XML update_delete_on_termination_flag_response\n";
	if(VolumeElement!=NULL)
		{
			volume_id = VolumeElement->GetText();
			VolumeElement=VolumeElement->NextSiblingElement();
		}
	else
		cout<<"Erro Parsing volume_id from XML update_delete_on_termination_flag_response\n";
	if(VolumeElement!=NULL)
		VolumeElement->QueryBoolText(&delete_on_termination);
	else cout<<"Error Parsing delete_on_termination from XML update_delete_on_termination_flag_response\n";
}
