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
		vector<image> images;
		string request_id;
		
		describe_images_response(const string &xml_doc);
		describe_images_response(){}
		
		
		string get_request_id()
		{
			return request_id;
		}
		
		vector<image> get_images() const
		{
			return images;
		}
	};
}
#endif
