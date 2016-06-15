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
#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include <string>
using namespace std;

namespace model
{
	///Class to Handle Snapshot Object
	class snapshot
	{
	private:
		string status;
		string snapshot_id;
		float volume_size;
		string volume_id;
		string start_time;

	public:
		///Constructor
		snapshot(string status_, string snapshot_id_, float volume_size_, string volume_id_, string start_time_)
		{
			status = status_;
			snapshot_id = snapshot_id_;
			volume_size = volume_size_;
			volume_id = volume_id_;
			start_time = start_time;
		}
		snapshot(){}
		///Getter for the Snapshot ID of the snapshot
		/**
			\return const string
		*/
		const string get_snapshot_id() const
		{
			return snapshot_id;
		}
		///Getter for the Volume ID 
		/**
			\return const string
		*/

		const string get_volume_id() const
		{
			return volume_id;
		}

		///Getter for the current Status of the Snapshot
		/**
			\return const string
		*/
		const string get_status() const
		{
			return status;
		}
		///Getter for the Volume Size of the Snapshot
		/**
			\return const float
		*/
		const float get_volume_size() const
		{
			return volume_size;
		}
		///Getter for the start time of the Snapshot
		/**
			\return const string 
		*/
		const string get_start_time() const
		{
			return start_time;
		}
	};
}
#endif
