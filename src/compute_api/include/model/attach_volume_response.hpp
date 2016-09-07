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
#ifndef ATTACH_VOLUMER_H
#define ATTACH_VOLUMER_H
#include <string>
using namespace std;

//! Models of Request Object Sent and Response Recieved 
namespace model
{
	/// Class to handle Attach Volume Response
	/**
		This Response Class has member variables and functions to get details of
		the volume that was requested to attach to a particular instance. 
	*/
	class attach_volume_response
	{
	private:
		string request_id; /**<  String \n Unique Request ID of the reponse recieved */
		string device;/**<  String \n Device Name of the Volume Attached */
		string instance_id;/**<  String \n Instance ID to which the Volume was attached */
		bool delete_on_termination;/**<  Bool \n Flag describing whether the volume will be deleted on instance Termination */
		string status; /**<  String \n Status of the request to attach volume */
		string volume_id;/**<  String \n Unique Id of the volume that was requested to attach */

  public:
		/// Constructor for Attach Volume Response
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		attach_volume_response(const string &xml_doc);
		attach_volume_response(){}
		///Getter for the Request ID
		/**
			\return  String
		*/
		const string& get_request_id() const 
		{
			return request_id;
		}
		///Getter for the Status of the Request
		/**
			\return  String
		*/
		const string& get_status() const
		{
			return status;
		}
		///Getter for the Device Name
		/**
			\return  String
		*/
		const string& get_device() const
		{
			return device;
		}
		///Getter for the Instance ID
		/**
			\return  String
		*/
		const string& get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the Volume Id
		/**
			\return  String
		*/
		const string& get_volume_id() const
		{
			return  volume_id;
		}
		///Getter for the Delete On Termination Flag 
		/**
			\return  Bool
		*/
		bool get_delete_on_termination() const
		{
			return delete_on_termination;
		}
	};

}
#endif

