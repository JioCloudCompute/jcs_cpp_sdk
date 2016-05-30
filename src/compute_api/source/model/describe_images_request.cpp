#include "src/compute_api/include/model/describe_images_request.h"

using namespace std;
using namespace model;

model::describe_images_request::describe_images_request()
{
	image_ids = vector<string>();
}

vector<string> * model::describe_images_request::get_image_ids() const
{
	return &image_ids;
}

void model::describe_images_request::set_image_ids(const vector<string> &image_id_set)
{
	image_ids.insert(image_ids.end(), image_id_set.begin(), image_id_set.end());
}
