#ifndef IMAGE_H
#define IMAGE_H
#include <string.h>
#include <string>
#include "block_device.h"
using namespace std;

namespace model{
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

		const bool get_is_public()
		{
			return is_public;
		}
		const string get_name()
		{
			return name;
		}
		const string get_image_id()
		{
			return image_id;
		}
		const string get_image_state()
		{
			return image_state;
		}
		const string get_architecture()
		{
			return architecture;
		}
		const string get_image_type()
		{
			return image_type;
		}

		const model::block_device get_block_device_mapping()
		{
			return block_device_mapping;
		}
	};
}
#endif
