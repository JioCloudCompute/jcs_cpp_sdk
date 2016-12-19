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
#ifndef CREATE_SNAPSHOT_H
#define CREATE_SNAPSHOT_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle create snaphot request
	/**
		This class manages the request for create snaphot. User can create an object and and initialize the needed arguments.
	*/
	class create_snapshot_request
	{
	private:
		string volume_id;

	public:
		/// Constructor
		create_snapshot_request(){}
		/// Getter for the private variable volume_id
		/**
			\return const string
		*/
		const string& get_volume_id() const;
		/// Setter for the private variable volume_id
		/**
			\param volume_id_ : volume id of the volume for which snapshot will be created(unique for each volume)
		*/
		void set_volume_id(const string& volume_id_);
	};
}
#endif

