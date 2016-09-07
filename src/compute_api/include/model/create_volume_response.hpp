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
#ifndef CREATE_VOLUMER_H
#define CREATE_VOLUMER_H
#include <string>
using namespace std;
namespace model
{
	/// Class to handle Create Volume Request's Response.
	/**
		This class object describes the volume created
	*/
	class create_volume_response
	{
	private:
		string request_id;
		string status;
		string volume_id;
		string snapshot_id;
		float size;
		string create_time;
    bool encrypted;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		create_volume_response(const string &xml_doc);
		create_volume_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string& get_request_id() const
		{
			return request_id;
		}
		///Getter for the Status of the volume created
		/**
			\return const string
		*/
		const string& get_status() const
		{
			return status;
		}
		///Getter for the ID of the volume created
		/**
			\return const string
		*/
		const string& get_volume_id() const
		{
			return volume_id;
		}
		///Getter for the ID of the snapshot to which the volume is attached
		/**
			\return const string
		*/
		const string& get_snapshot_id() const
		{
			return snapshot_id;
		}
		///Getter for the Size of the Volume Created
		/**
			\return float
		*/
		float get_size() const
		{
			return size;
		}
		///Getter for the time Volume was created
		/**
			\return const string
		*/
		const string& get_create_time() const
		{
			return create_time;
		}

    /**
     * Whether the created/creating volume is empty or not.
     * */
    bool get_encrypted() const
    {
      return encrypted;
    }

	};
}
#endif

