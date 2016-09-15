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
#ifndef IMAGE_H
#define IMAGE_H
#include <string.h>
#include <string>
#include "model/block_device.hpp"
using namespace std;

namespace model{
	/// Class Describing Details of a Image.
	/**
		
	*/
	class image
	{
	private:
		bool is_public;
		string name;
		string image_id;
		string image_state;
		string architecture;
		string image_type;
		model::block_device block_device_mapping;

	public:
		
		image(){}
		///Constructor
		/**
			Sets the Private Member variables.
			\param block_device_mapping : A block_device Object
			\param name_ : Name of the OS os the image
			\param image_id : ID of the Image
			\param image_state_ : Current State of the Image 
			\param architecture : Architecture of the OS of the Image
			\param image_type_ : Type of the image
		*/

		image(model::block_device block_device_mapping_,string name_, bool is_public_,  string image_id_, string image_state_, string architecture_, 
				string image_type_)
		{
			is_public = is_public_;
			name = name_;
			image_id = image_id_;
			image_state = image_state_;
			architecture = architecture_;
			image_type = image_type_;
			block_device_mapping = block_device_mapping_;
		}
		///Getter for Is Public Bool Flag of the Image
		/**
			\return const bool
		*/
		bool get_is_public() const
		{
			return is_public;
		}
		///Getter for the name of the OS of the Image
		/**
			\return const string
		*/
		const string& get_name() const
		{
			return name;
		}
		///Getter for the Unique image ID of the Image
		/**
			\return const string
		*/
		const string& get_image_id() const
		{
			return image_id;
		}
		///Getter for the State of the Image
		/**
			\return const string

		*/
		const string& get_image_state() const
		{
			return image_state;
		}
		///Getter for the architecture of the OS of the Image
		/**
			\return const string
		*/
		const string& get_architecture() const
		{
			return architecture;
		}
		///Getter for the Type of the Image
		/**
			\return const string
		*/
		const string& get_image_type() const
		{
			return image_type;
		}
		///Getter for the Block Device on which Image Resides
		/**
			\return const vector<block_device>
			A vector of Objects of the class Block Device
		*/
		const model::block_device& get_block_device_mapping() const
		{
			return block_device_mapping;
		}
	};
}
#endif
