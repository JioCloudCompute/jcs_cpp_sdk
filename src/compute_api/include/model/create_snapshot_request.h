#ifndef CREATE_SNAPSHOT_H
#define CREATE_SNAPSHOT_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class create_snapshot_request
	{
	private:
		string volume_id;

	public:
		create_snapshot_request();
		
	const string get_volume_id();

		void set_volume_id(string volume_id_);
	};
}
#endif

