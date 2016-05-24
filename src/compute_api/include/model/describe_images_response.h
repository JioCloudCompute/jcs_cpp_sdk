#include "image.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

namespace model{
	class describe_images_response
	{
	private:
		int image_number;
		map<string,Image> Images;
		string Request_Id;

	public:
		describe_images_response(const string xml_doc);
		describe_images_response(){
		}
		
		string Get_Request_Id() const{
namespace model
{
	class describe_images_response
	{
		public:
		map<string,Image> Images;
		string Request_Id;

		
		describe_images_response(const string xml_doc);
		describe_images_response()
		{
		}
		
		
		string Get_Request_Id(){
			return Request_Id;
		}
		void Set_Request_Id(string Id){
			Request_Id = Id;
		}

		void Add_Image(Image& data){
			Images[data.Get_imageId()]=data;
		}

		void Increment()
		{
			image_number++;
		}
		int Get_NumberOfImages() const
		{
			return image_number;
		}
		map<string, Image> Get_Images() const
		{
			return Images;
}
		void Set_Image(const Image& data){

		}
		void Add_Image(const Image& data){
			Images[data.imageId]=data;
		}

	};
}
