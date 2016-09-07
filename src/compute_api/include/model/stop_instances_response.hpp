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
#ifndef STOP_INSTANCER_H
#define STOP_INSTANCER_H
#include <string>
#include <map>
#include "model/instance_set.hpp"
#include <vector>

using namespace std;
using namespace model;

namespace model
{
	/// Class to handle Stop Instances Request's Response
	/**
		This Response Class has member functions that returns the description of the Instances requested to stop.  
	*/
	class stop_instances_response
	{
	private:
		string request_id;
		vector<model::instance_state_set> instances;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		stop_instances_response(const string &xml_doc);
		stop_instances_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string& get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of the instances that were requested to stop
		/**
			\return const vector<model::instance_set>
			A vector of objects of class instance_set
		*/
		const vector<model::instance_state_set>& get_instances() const
		{
			return instances;
		}

	};
}
#endif
