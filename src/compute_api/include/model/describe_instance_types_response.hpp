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
#ifndef DESCRIBE_INSTANCE_TYPESR_H
#define DESCRIBE_INSTANCE_TYPESR_H
#include <map>
#include "model/instance_type.hpp"
#include <vector>

using namespace std;
using namespace model;

namespace model
{	
	/// Class to handle Describe Instance Type Request's Response
	/**
		This Response Class has member functions that returns the description of instance types requested for.  
	*/
	class describe_instance_types_response
	{
	private:
		string request_id;
		vector<model::instance_type>instance_type_set;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		describe_instance_types_response(const string &xml_doc);
		describe_instance_types_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string& get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of Intance Types requested
		/**
			\return const vector<model::instance_type>  
			A vector of objects of class instance_type
		*/
		const vector<model::instance_type>& get_instance_types() const
		{
			return instance_type_set;
		}
	};
}
#endif

