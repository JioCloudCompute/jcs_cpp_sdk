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
#include "model/detach_volume_response.hpp"
#include "XMLParser.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

detach_volume_response::detach_volume_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode=doc.FirstChild();

	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{	if(Element->GetText()!=NULL)request_id = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else cout<<"Error Parsing request_id from detach_volume_response\n";
	
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)device = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else cout<<"Error Parsing device name from detach_volume_response\n";

	if(Element!=NULL)
	{	
		if(Element->GetText()!=NULL)instance_id = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else cout<<"Error Parsing instance_id from XML detach_volume_response\n";
	if(Element!=NULL)
	{
		Element->QueryBoolText(&delete_on_termination);
		Element = Element->NextSiblingElement();
	}
	else cout<<"Error Parsing delete_on_termination from XML detach_volume_response\n";
	
	if(Element!=NULL)
	{
		if(Element->GetText()!=NULL)status = Element->GetText();
		Element = Element->NextSiblingElement();
	}
	else cout<<"Error Parsing status from XML detach_volume_response\n";
	if(Element!=NULL)
		{if(Element->GetText()!=NULL)volume_id = Element->GetText();}
	else cout<<"Error Parsing volume_id from detach_volume_response\n";
}
