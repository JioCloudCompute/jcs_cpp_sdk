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
#ifndef INSTANCE_SET_H
#define INSTANCE_SET_H
#include <string>
using namespace std;

namespace model
{	///Class Describing the Details of a Instance
	/**
		
	*/
	class instance_set
	{
	private:
		string instance_id;
		string current_state;
		string previous_state;
	public:
		///Constructor
		
		instance_set(string instance_id_, string current_state_, string previous_state_)
		{
			instance_id = instance_id_;
			current_state = current_state_;
			previous_state = previous_state_;
		}
		instance_set(){}
		///Getter for the Instance ID
		/**
			\return const string
		*/
		const string get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the Current State of the Instance
		/**
			\return const string
			pending, running, shutting-down, terminated, stopping, stopped
		*/

		const string get_current_state() const
		{
			return current_state;
		}
		///Getter for the Previous State of the Instance
		/**
			\return const string
			pending, running, shutting-down, terminated, stopping, stopped
		*/
		const string get_previous_state() const
		{
			return previous_state;
		}
	};
}
#endif
