#include "src/compute_api/include/model/describe_images_request.h"

using namespace std;
using namespace model;

model::describe_images_request::describe_images_request()
{
	image_ids = vector<string>();
}

const vector<string>* model::describe_images_request::get_image_ids()
{
	return &image_ids;
}

void model::describe_images_request::set_image_ids(vector<string> &image_id_set)
{
	for(int i=0 ; i<image_id_set.size() ; i++)
	{
		image_ids.push_back(image_id_set[i]);
	}
}
