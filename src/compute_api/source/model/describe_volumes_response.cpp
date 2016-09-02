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

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

model::describe_volumes_response::describe_volumes_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
  if (RootNode) {
    XMLElement *Element = RootNode->FirstChildElement("requestId");

    if(Element and Element->GetText())
      request_id = Element->GetText();

    Element = RootNode->FirstChildElement("volumeSet");
    XMLElement * ListElement = NULL;
    if (Element)
      ListElement = Element->FirstChildElement("item");

    while(ListElement != NULL)
    {
      /*
         <item>
         <status>in-use</status>
         <encrypted>false</encrypted>
         <volumeType>standard</volumeType>
         <volumeId>3b5c39bb-5e03-4967-ae32-0ed094b27672</volumeId>
         <attachmentSet>
         <item>
         <device>/dev/vda</device>
         <instanceId />
         </item>
         </attachmentSet>
         <snapshotId />
         <createTime>2016-03-01T11:21:39.000000</createTime>
         <size>4</size></item> 
         */
      XMLElement *VolumeSet,*SubElement;
      string status,volume_id, device, instance_id, snapshot_id,create_time;
      bool encrypted = false;
      string volume_type;
      float size;

      VolumeSet =  ListElement->FirstChildElement("status");
      if(VolumeSet and VolumeSet->GetText())
        status = VolumeSet->GetText();

      //Check and get
      VolumeSet = ListElement->FirstChildElement("encrypted");

      //read
      if (VolumeSet and VolumeSet->GetText())
        if(!strcmp("true", VolumeSet->GetText()))
          encrypted = true;

      VolumeSet = ListElement->FirstChildElement("volumeType");
      if (VolumeSet and VolumeSet->GetText())
        volume_type = VolumeSet->GetText();

      //else cout<<"Error Parsing status from XML describe_volumes_response\n";
      VolumeSet = ListElement->FirstChildElement("volumeId");
      if(VolumeSet and VolumeSet->GetText())
        volume_id = VolumeSet->GetText();

      VolumeSet = ListElement->FirstChildElement("attachmentSet");
      if(VolumeSet)
      {
        SubElement = VolumeSet->FirstChildElement("item");
        if (SubElement) {
          XMLElement * child = SubElement->FirstChildElement("device");
          if (child and child->GetText())
            device = child->GetText();

          child = SubElement->FirstChildElement("instanceId");
          if (child and child->GetText())
            instance_id = child->GetText();
        }
      }

      VolumeSet = ListElement->FirstChildElement("snapshotId");
      if(VolumeSet and VolumeSet->GetText())
        snapshot_id = VolumeSet->GetText();

      VolumeSet = ListElement->FirstChildElement("createTime");
      if(VolumeSet and VolumeSet->GetText())
        create_time= VolumeSet->GetText();

      VolumeSet = ListElement->FirstChildElement("size");
      if (VolumeSet and VolumeSet->GetText())
        VolumeSet->QueryFloatText(&size);

      model::volume data(status, volume_id, device, instance_id, snapshot_id, create_time, size, encrypted, volume_type);
      volume_set.push_back(data);

      ListElement=ListElement->NextSiblingElement();

    }
  }
}
