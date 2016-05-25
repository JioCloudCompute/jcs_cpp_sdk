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
		map<string,Image> Images;
		string Request_Id;
		int image_number;
		
		describe_images_response(const string xml_doc);
		describe_images_response()
		{
		}
		
		
		char *get_request_Id(){
			return Request_Id.c_str();
		}
		void set_Request_Id(string Id){
			Request_Id = Id;
		}

		void add_Image(Image& data){
			Images[data.Get_imageId()]=data;
		}

		void increment()
		{
			image_number++;
		}
		int* get_NumberOfImages() const
		{
			return &image_number;
		}
		map<string, Image> *get_Images() const
		{
			return &Images;}
		void Set_Image(const Image& data){

		}
		void Add_Image(const Image& data){
			Images[data.Get_imageId()]=data;
		}

	};
}
#endif
