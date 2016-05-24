#include <vector>
#include <string>

using namespace std;
namespace model
{
	class delete_snapshot_request
	{
	private:
		string snapshot_id;

	public:
		delete_snapshot_request();
	const string get_snapshot_id();

		void set_snapshot_id(string snapshot_id_);
	};
}