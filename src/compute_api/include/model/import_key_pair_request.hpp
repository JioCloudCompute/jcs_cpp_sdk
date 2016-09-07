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
#ifndef IMPORT_KEY_PAIR_H
#define IMPORT_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle import key pair request
	/**
		This class manages the request for import key pair. User can create an object and and initialize the needed arguments.
	*/
	class import_key_pair_request
	{
	private:
		string key_name;
		string public_key_material;

	public:
		/// Constructor
		import_key_pair_request();
		/// Getter for the private variable key_name
		/**
			\return const string
		*/
		const string& get_key_name() const;
		/// Setter for the private variable key_name
		/**
			\param key_name_ : key name (unique for each key)
		*/
		void set_key_name(const string& key_name_);

		/// Getter for the private variable public_key_material
		/**
			\return const string
		*/
		const string& get_public_key_material() const;
		/// Setter for the private variable public_key_material
		/**
			\param public_key_material_ : base64 encoded ssh pubic key material. If ssh pubilc key is like "ssh-rsa AACDF3498934 ...", it should be base64 encoded.
		*/
		void set_public_key_material(const string& public_key_material_b64);
    /**
     * This takes ssh public key in ssh public key format which should be PEM format. Key should be like "ssh-rsa AACDF3498934 ...".
     * */
    void set_public_key_material_raw(const string& pubilc_key_material);
	};
}
#endif
