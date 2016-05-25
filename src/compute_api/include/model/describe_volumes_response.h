#ifndef DESCRIBE_VOLUMESR_H
#define DESCRIBE_VOLUMESR_H
#include <map>
#include "src/compute_api/include/model/volume.h"
using namespace std;
using namespace model;

namespace model
{
	class describe_volumes_response
	{
	private:
		string request_id;
		map<string, model::volume>volume_set;

	public:
		describe_volumes_response(const string &xml_doc);

		const string get_request_id()
		{
			return request_id;
		}
		const map<string, model::volume> get_volume_set()
		{
			return volume_set;
		}
	};
}
#endif
