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
#ifndef CREATE_VOLUME_H
#define CREATE_VOLUME_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle create volume request
	/**
		This class manages the request for create volume. User can create an object and and initialize the needed arguments.
	*/
	class create_volume_request
	{
	private:
		string snapshot_id;
		int size;

	public:
		/// Constructor
		create_volume_request();
		/// Getter for the private variable snapshot_id
		/**
			\return const string
		*/
		const string get_snapshot_id() const;
		/// Setter for the private variable snapshot_id
		/**
			\param snapshot_id_ (optional) : snapshot id to create volume similar to the volume from which snapshot is created(unique for each snapshot). Not necessary if size is given
		*/
		void set_snapshot_id(const string& snapshot_id_);
		/// Getter for the private variable size
		/**
			\return const string
		*/
		const int get_size() const;
		/// Setter for the private variable size
		/**
			\param size_(optional) : size of the volume. Not necessary if snapshot id is given
		*/
		void set_size(const int& size_);
	};
}
#endif
