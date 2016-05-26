#ifndef DELETE_VOLUME_H
#define DELETE_VOLUME_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class delete_volume_request
	{
	private:
		string volume_id;

	public:
		delete_volume_request();
		const string get_volume_id();

		void set_volume_id(string volume_id_);
	};
}
#endif

