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
#include "model/run_instances_response.hpp"
#include "XMLParser.h"
#include <iostream>
#include <utils.hpp>


using namespace std;
using namespace tinyxml2;
using namespace model;
using namespace utils;


run_instances_response::run_instances_response(const string &xml_doc)
{	

  XMLDocument doc;
  doc.Parse(xml_doc.c_str());
  //Root
  const XMLNode *RootNode = doc.FirstChild();
  if (RootNode) {
    set_string_value(RootNode, "requestId", request_id);
    const XMLElement* Element = RootNode->FirstChildElement("instancesSet");
    if(Element) {  
      const XMLElement *ListElement = Element->FirstChildElement("item");
      const XMLElement *InstanceElement;
      while(ListElement != NULL)
      {
        block_device_instance block;
        group_set group;
        vector<group_set> groups;
        vector<block_device_instance> blocks;
        string vpc_id, dns_name, instance_id, instance_state,image_id,private_dns_name,key_name, launch_time, subnet_id, instance_type, private_ip_address, ip_address;

        InstanceElement =  ListElement->FirstChildElement("blockDeviceMapping");
        if (InstanceElement) { 
          const XMLElement* blockListElement = InstanceElement->FirstChildElement("item");
          while(blockListElement != NULL)
          {
            set_string_value(blockListElement, "status", block.status);
            set_string_value(blockListElement, "deviceName", block.device_name);
            set_bool_value(blockListElement, "deleteOnTermination", block.delete_on_termination);
            set_string_value(blockListElement, "volumeId", block.volume_id);
            set_bool_value(blockListElement, "encrypted", block.encrypted);
            blocks.push_back(block);

            blockListElement=blockListElement->NextSiblingElement();
          }
        }

        set_string_value(ListElement, "vpcId", vpc_id);
        set_string_value(ListElement, "dnsName", dns_name);
        set_string_value(ListElement, "instanceId", instance_id);
        set_string_value(ListElement, "instanceState", instance_state);
        set_string_value(ListElement, "imageId", image_id);
        set_string_value(ListElement, "privateDnsName", private_dns_name);
        set_string_value(ListElement, "keyName", key_name);
        set_string_value(ListElement, "launchTime", launch_time);
        set_string_value(ListElement, "subnetId", subnet_id);
        InstanceElement = ListElement->FirstChildElement("groupSet");
        if (InstanceElement) {
          const XMLElement * gse = InstanceElement->FirstChildElement("item");
          while(gse) {
            set_string_value(gse, "groupName", group.group_name);
            set_string_value(gse, "groupId", group.group_id);
            groups.push_back(group);
            gse = gse->NextSiblingElement();
          }
        }
        set_string_value(ListElement, "instanceType", instance_type);
        set_string_value(ListElement, "privateIpAddress", private_ip_address);
        set_string_value(ListElement, "ipAddress", ip_address);

        instance data(blocks,dns_name, instance_id, instance_state, image_id, private_dns_name, key_name, launch_time, subnet_id, groups, vpc_id, instance_type, private_ip_address, ip_address);

        instances.push_back(data);

        ListElement = ListElement->NextSiblingElement();

      }
    }
  }
}


