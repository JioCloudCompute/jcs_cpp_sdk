#ifndef CREATE_VOLUME_H
#define CREATE_VOLUME_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class create_volume_request
	{
	private:
		string snapshot_id;
		int size;

	public:
		create_volume_request();
	const string get_snapshot_id();

		void set_snapshot_id(string snapshot_id_);

	const int get_size();
		
		void set_size(int size_);
	};
}
#endif
