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
#ifndef VOLUME_H
#define VOLUME_H
#include <string>
#include <map>
using namespace std;

namespace model
{
	///Class to Handle Volume Oject
	class volume
	{
	private:
		string status;
    bool  encrypted;
		string volume_id;
		string device;
		string instance_id;
		string snapshot_id;
		string create_time;
    string volume_type;
		unsigned size;

	public:
		///Constructor
		volume(const string& status_, const string& volume_id_, const string& device_, const string& instance_id_, const string& snapshot_id_, const string& create_time_, unsigned size_,
        bool encrypted_, const string& volume_type):status(status_), volume_id(volume_id_), device(device_), instance_id(instance_id_), snapshot_id(snapshot_id_),
                      create_time(create_time_), size(size_), encrypted(encrypted_), volume_type(volume_type)
		{
		}

		volume(){}
		///Getter for the Current Status of the Volume Object
		/**
			\return const string
		*/
		const string& get_status() const
		{
			return status;
		}
		///Getter for the current volume ID
		/**
			\return const string
		*/
		const string& get_volume_id() const
		{
			return volume_id;
		}
		///Getter for the Device ID of the Volume Storage
		/**
			\return const string
		*/
		const string& get_device() const
		{
			return device;
		}
		///Getter for the Instance ID to which the Volume is attached
		/**
			return const string
		*/
		const string& get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the Snapshot ID 
		/**
			\return const string
		*/
		const string& get_snapshot_id() const
		{
			return snapshot_id;
		}
		///Getter for the Create Time of the Volume
		/**
			\return const string
		*/
		const string& get_create_time() const
		{
			return create_time;
		}
		///Getter for the Size of the Volume
		/**
			\return const float
		*/
		unsigned get_size() const
		{
			return size;
		}

    bool get_encrypted() const
    {
        return encrypted;
    }

    const string& get_volumetype() const
    {
      return volume_type;
    }
	};
}
#endif
