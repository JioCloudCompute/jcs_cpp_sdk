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

		void Set_Image(const Image& data){

		}
		void Add_Image(const Image& data){
			Images[data.imageId]=data;
		}

	};
}