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
#ifndef GET_PASSWORD_DATA_H
#define GET_PASSWORD_DATA_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle attach volume request
	/**
		This class manages the request for attach volume. User can create an object and and initialize the needed arguments.
	*/
	class get_password_data_request
	{
	private:
		string instance_id;
		string private_key_file;
		string passphrase;

	public:
		/// Constructor
		get_password_data_request(){}

		/// Getter for the private variable instance_id
		/**
			\return const string
		*/ 
		const string& get_instance_id() const;

		/// Setter for the private variable instance_id 
		/**
			\param instance_id_ : instance id  with which volume will be attached(unique for each instance)
		*/
		void set_instance_id(const string& instance_id_);

		/// Getter for the private variable private_key_file
		/**
			\return const string
		*/
		const string& get_private_key_file () const;

		/// Setter for the private variable private_key_file
		/**
			\param private_key_file_ (optional): path to the private key file
		*/
		void set_private_key_file(const string& private_key_file_);

		/// Getter for the private variable passphrase 
		/**
			\return const string
		*/
		const string& get_passphrase() const;

		/// Setter for the private variable passphrase 
		/**
			\param passphrase_ (optional): password if the private key file is password protected
		*/
		void set_passphrase(const string& passphrase_);


	};
}
#endif

