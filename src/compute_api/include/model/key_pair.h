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
#ifndef KEY_PAIR_H
#define KEY_PAIR_H
#include <string>
using namespace std;
namespace model
{
	///Class To handle Key-Pair Object
	class key_pair
	{
	private:
		string key_name;
		string key_fingerprint;
	public:
		///Constructor
		key_pair(string key_name_, string key_fingerprint_)
		{
			key_name = key_name_;
			key_fingerprint = key_fingerprint_;
		}
		key_pair(){}
		///Getter for the Key-Name of the Key
		/**
			\return const string
		*/
		const string get_key_name() const
		{
			return key_name;
		}
		///Getter for the Key-FingerPrint of the Key
		/**
			\return const string
		*/
		const string get_key_fingerprint() const
		{
			return key_fingerprint;
		}
	};
}
#endif
