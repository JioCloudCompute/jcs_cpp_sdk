#ifndef IMPORT_KEY_PAIRR_H
#define IMPORT_KEY_PAIRR_H
#include <string>
using namespace std;
namespace model
{
	class import_key_pair_response
	{
	private:
		string request_id;
		model ::key_pair key;
	public:
		import_key_pair_response(const string &xml_doc);

		const model::key_pair get_key()
		{
			return key;
		}

		const string get_request_id()
		{
			return request_id;
		}
	};

}
#endif

