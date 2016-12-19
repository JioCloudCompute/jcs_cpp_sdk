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
#ifndef DESCRIBE_VOLUMES_H
#define DESCRIBE_VOLUMES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle describe snapshots request
	/**
		This class manages the request for describe snapshots. User can create an object and and initialize the needed arguments.
	*/
	class describe_volumes_request
	{
	private:
		vector<string> volume_ids;
		int max_results;
		string next_token;
		bool detail;

	public:
		/// Constructor
		describe_volumes_request();
		/// Getter for the private variable volume_id
		/**
			\return const vector<string> *
		*/
		const vector<string> *get_volume_ids() const;
		/// Setter for the private variable volume_id
		/**
			\param volume_set (optional): reference to a vector of volume ids
		*/
		void set_volume_ids(const vector<string>& volume_id_set);

		/// Getter for the private variable max_results
		/**
			\return const int
		*/
		int get_max_results() const;
		/// Setter for the private variable max_results
		/**
			\param max_results_ (optional): Max number of results to be shown in response.
		*/
		void set_max_results(int max_results_);
		/// Getter for the private variable next_token
		/**
			\return const string
		*/
		const string& get_next_token() const;
		/// Setter for the private variable next_token
		/**
			\param next_token_ (optional): NextToken - Id of last snapshot seen if max number of results is less than total snapshots
		*/
		void set_next_token(const string& next_token_);
		/// Getter for the private variable detail
		/**
			\return const bool
		*/
		bool get_detail() const;
		/// Setter for the private variable detail
		/**
			\param detail_ (optional): Detail - by default this is true. Set to false to will supress detailed response
		*/
		void set_detail(bool detail_);
		
	};
}
#endif

