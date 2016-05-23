#include <vector>
#include <string>
#include "src/compute_api/include/model/describe_images_request.h"

using namespace std;

describe_images_request()
{
	describe_images_request = vector<string>();
}

vector<string> get_image_ids()
{
	return image_ids;
}

void set_image_ids(vector<string>image_id_set);
{
	for(int i=0 ; i<image_id_set.size() ; i++)
	{
		image_ids.push_back(image_id_set[i]);
	}
}
