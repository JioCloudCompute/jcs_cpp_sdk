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
#ifndef GET_PASSWORD_H
#define GET_PASSWORD_H
#include <string>
using namespace std;

namespace model
{
	/// Class to handle Get Password Request's Response
	/**
	*/
	class get_password_data_response
	{
	private:
		string request_id;
		string password_data;
		string instance_id;
		string timestamp;
	public:
		/// Constructor for Get Password Data Response
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		get_password_data_response(const string &xml_doc);
		///Getter for the Request ID
		/**
			\return  String
		*/
		const string& get_request_id() const 
		{
			return request_id;
		}
		///Getter for the Password Data
		/**
			\return  String
		*/
		const string& get_password_data() const
		{
			return password_data;
		}
		///Getter for the Instance ID
		/**
			\return  String
		*/
		const string& get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the time stamp
		/**
			\return  String
		*/
		const string& get_timestamp() const
		{
			return  timestamp;
		}

	};

}
#endif

