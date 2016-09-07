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
#ifndef IMPORT_KEY_PAIRR_H
#define IMPORT_KEY_PAIRR_H
#include <string>
#include <vector>
#include "model/key_pair.hpp"
using namespace std;
namespace model
{
	/// Class to handle Import Key Pair Request's Response
	/**
		This Response Class has member functions that returns description of the Key pair Imported  
	*/
	class import_key_pair_response
	{
	private:
		string request_id;
		model::key_pair key;
	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		import_key_pair_response(const string &xml_doc);
		///Getter for the Description of the key pair
		/**
			\return const vector<key_pair>
			A vector of objects of class key_pair
		*/
		const model::key_pair get_key() const
		{
			return key;
		}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
	};

}
#endif

