#include <vector>
#include <string>

using namespace std;

class describe_images_request
{
private:
	vector<string> image_ids;

public:
	vector<string> get_image_ids();
	
	void set_image_ids(vector<string>image_id_set);
};