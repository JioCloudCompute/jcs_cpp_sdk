#ifndef SHOW_DELETE_H
#define SHOW_DELETE_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle show delete on termination flag request
	/**
		This class manages the request for show delete on termination flag. User can create an object and and initialize the needed arguments.
	*/
	class show_delete_on_termination_flag_request
	{
	private:
		string volume_id;

	public:
		///Constructor
		show_delete_on_termination_flag_request();
		/// Getter for the private variable volume_id
		/**
			\return const string
		*/
		const string get_volume_id() const;
		/// Setter for the private variable volume_id
		/**
			\param volume_id_ : volume id(unique for each volume)
		*/
		void set_volume_id(const string& volume_id_);
	};
}
#endif
