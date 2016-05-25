#ifndef DESCRIBE_IMAGESR_H
#define DESCRIBE_IMAGESR_H
#include "image.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

namespace model
{
	class describe_images_response
	{
		public:
		map<string,Image> images;
		string request_id;
		int image_number;
		
		describe_images_response(const string &xml_doc);
		describe_images_response()
		{
		}
		
		
		string get_request_id(){
			return request_id;
		}
		
		int get_number_Of_images() const
		{
			return image_number;
		}
		map<string, Image> get_images() const
		{
			return images;}
		void Set_Image(const Image& data){

		}
	

	};
}
#endif
