#ifndef DESCRIBE_IMAGES_H
#define DESCRIBE_IMAGES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class describe_images_request
	{
	private:
		vector<string> image_ids;

	public:
		describe_images_request();
	const vector<string>* get_image_ids();
		
		void set_image_ids(vector<string> &image_id_set);
	};
}

#endif
