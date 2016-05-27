#ifndef UPDATE_DELETE_H
#define UPDATE_DELETE_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle update delete on termination flag request
	/**
		This class manages the request for update delete on termination flag. User can create an object and and initialize the needed arguments.
	*/
	class update_delete_on_termination_flag_request
	{
	private:
		string volume_id;
		bool delete_on_termination;

	public:		
		///Constructor
		update_delete_on_termination_flag_request();
		/// Getter for the private variable volume_id
		/**
			\return const string
		*/
		const string get_volume_id();
		/// Setter for the private variable volume_id
		/**
			\param volume_id_ : Particular volume id to be updated for DeleteOnTermination flag.
		*/
		void set_volume_id(string volume_id_);
		/// Getter for the private variable delete_on_termination
		/**
			\return const bool
		*/
		const bool get_delete_on_termination();
		/// Setter for the private variable delete_on_termination
		/**
			\param delete_on_termination_ : Boolean value for the DeleteOnTermination flag 
		*/
		void set_delete_on_termination(bool delete_on_termination_);
	};
}
#endif
