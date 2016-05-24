#include <string.h>
#include <string>
#include "block_device.h"
using namespace std;

namespace model{
	class Image
	{
	private:
		bool isPublic;
		string name;
		string imageId;
		string imageState;
		string architecture;
		string imageType;
		model::block_device block_device_mapping;
	public:
		void Set_isPublic(bool &value)
		{
			this->isPublic = value; 
		}
		void Set_name(string name){
			this->name = name;
		}
		void Set_imageId(string imageId)
		{
			this->imageId = imageId;
		}
		void Set_imageState(string imageState)
		{
			this->imageState = imageState;
		}
		void Set_architecture(string architecture)
		{
			this->architecture = architecture;
		}
		void Set_imageType(string imageType)
		{
			this->imageType = imageType;
		}
		void Set_block_device(model::block_device &block_device_mapping)
		{
			this->block_device_mapping = block_device_mapping;
		}

		bool Get_isPublic() const
		{
			return isPublic;
		}
		string Get_name() const{
			return name;
		}
		string Get_imageId() const
		{
			return imageId;
		}
		string Get_imageState() const
		{
			return imageState;
		}
		string Get_architecture() const
		{
			return architecture;
		}
		string Get_imageType() const
		{
			return imageType;
		}

		model::block_device Get_block_device_mapping() const
		{
			return block_device_mapping;
		}


	};
}