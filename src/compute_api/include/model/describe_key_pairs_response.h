#ifndef DESCRIBE_KEYR_H
#define DESCRIBE_KEYR_H
#include <string>
#include <map>
#include "src/compute_api/include/model/key_pair.h"
using namespace std;
using namespace model;

namespace model
{
	class describe_key_pairs_response
	{
	private:
		string request_id;
		map <string, model::key_pair>key_pairs;
	public:
		describe_key_pairs_response(const string &xml_doc);

		const map<string, model::key_pair> get_key_pairs()
		{
			return key_pairs;
		}

		const string get_request_id()
		{
			return request_id;
		}
	};
}
#endif

