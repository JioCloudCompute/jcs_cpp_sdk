#ifndef UPDATE_DELETE_H
#define UPDATE_DELETE_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class update_delete_on_termination_flag_request
	{
	private:
		string volume_id;
		bool delete_on_termination;

	public:
		update_delete_on_termination_flag_request();
		const string get_volume_id();

		void set_volume_id(string volume_id_);

		const bool get_delete_on_termination();

		void set_delete_on_termination(bool delete_on_termination_);
	};
}
#endif
