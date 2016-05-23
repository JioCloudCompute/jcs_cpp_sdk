#include "image.h"
#include <string>
#include <vector>
#include <map>
using namespace std;
class describe_images_responses
{
	describe_images_responses(const string xml_doc);
	
	
	string Get_Request_Id(){
		return Request_Id;
	}
	void Set_Request_Id(string Id){
		this.Request_Id = Id;
	}

	void Set_Image(const Image& data){

	}
	void Add_Image(const Image& data){
		Images[data.ImageId]=data;
	}

	private:
		map<string,Image> Images;
		string Request_Id;


}