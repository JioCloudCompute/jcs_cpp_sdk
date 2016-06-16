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
#ifndef UPDATE_DELETE_H
#define UPDATE_DELETE_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle update delete on termination flag request
	/**
		This class manages the request for update delete on termination flag. User can create an object and and initialize the needed arguments.
	*/
	class update_delete_on_termination_flag_request
	{
	private:
		string volume_id;
		bool delete_on_termination;

	public:		
		///Constructor
		update_delete_on_termination_flag_request();
		/// Getter for the private variable volume_id
		/**
			\return const string
		*/
		const string get_volume_id() const;
		/// Setter for the private variable volume_id
		/**
			\param volume_id_ : Particular volume id to be updated for DeleteOnTermination flag.
		*/
		void set_volume_id(const string& volume_id_);
		/// Getter for the private variable delete_on_termination
		/**
			\return const bool
		*/
		const bool get_delete_on_termination() const;
		/// Setter for the private variable delete_on_termination
		/**
			\param delete_on_termination_ : Boolean value for the DeleteOnTermination flag 
		*/
		void set_delete_on_termination(const bool& delete_on_termination_);
	};
}
#endif
