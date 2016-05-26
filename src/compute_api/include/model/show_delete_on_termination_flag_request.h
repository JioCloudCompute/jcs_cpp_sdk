#ifndef SHOW_DELETE_H
#define SHOW_DELETE_H
#include <vector>
#include <string>

using namespace std;
namespace model
{
	class show_delete_on_termination_flag_request
	{
	private:
		string volume_id;

	public:
		show_delete_on_termination_flag_request();
		const string get_volume_id();

		void set_volume_id(string volume_id_);
	};
}
#endif
