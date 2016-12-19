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
#ifndef DETACH_VOLUMER_H
#define DETACH_VOLUMER_H
#include <string>
using namespace std;
namespace model
{	
	/// Class to handle Detach Volume Request's Response
	/**
		This Response Class has member functions that returns the description of the Volume requested to detach.  
	*/
	class detach_volume_response
	{
	private:
		string request_id;
		string device;
		string instance_id;
		bool delete_on_termination;
		string status;
		string volume_id;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		detach_volume_response(const string &xml_doc);
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string& get_request_id() const
		{
			return request_id;
		}
		///Getter for the Current Status of the Volume
		/**
			\return const string
		*/
		const string& get_status() const
		{
			return status;
		}
		///Getter for the Device Name of the Volume
		/**
			\return const string
		*/
		const string& get_device() const
		{
			return device;
		}
		///Getter for the instance ID from which the volume got Dettached
		/**
			\return const string
		*/
		const string& get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the Volume ID
		/**
			\return const string
		*/
		const string& get_volume_id() const
		{
			return  volume_id;
		}
		///Getter for the Delete On termination Flag
		/**
			\return const bool
			True if volume get's Deleted** on Termination of the instance to which the it is attached
		*/
		bool get_delete_on_termination() const
		{
			return delete_on_termination;
		}
	};

}
#endif

