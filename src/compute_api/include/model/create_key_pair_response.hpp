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
#ifndef CREATE_KEY_PAIRR_H
#define CREATE_KEY_PAIRR_H
#include <string>
#include <model/key_pair.hpp>
using namespace std;
namespace model
{
	/// Class to handle Create Key Pair Request's Response.
	/**
		This class object describes the key fingerprint, key material, key name of the created key pair.
	*/
	class create_key_pair_response
	{
	private:
    model::key_pair keypair;
		/*string key_fingerprint;
		string key_material;
		string key_name;*/
		string request_id;
	public:
		/// Constructor 
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		create_key_pair_response(const string &xml_doc);
		create_key_pair_response(){}

		///Getter for the Key FingerPrint of the Key Created
		/**
			\return const string
		*/
		const string get_key_fingerprint() const
		{
			return keypair.get_key_fingerprint();
		}
		///Getter for the Key Material(RSA Private Key) of the Key Created
		/**
			\return const string
		*/
		const string get_key_material() const
		{
			return keypair.get_key_material();
		}
		///Getter for the Key Name of the Key Created
		/**
			\return const string
		*/
		const string get_key_name() const
		{
			return keypair.get_key_name();
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

