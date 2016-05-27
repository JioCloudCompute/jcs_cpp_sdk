#ifndef DELETE_SNAPSHOT_H
#define DELETE_SNAPSHOT_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle delete snapshot request
	/**
		This class manages the request for delete snapshot. User can create an object and and initialize the needed arguments.
	*/
	class delete_snapshot_request
	{
	private:
		string snapshot_id;

	public:
		/// Constructor
		delete_snapshot_request();
		/// Getter for the private variable snapshot_id
		/**
			\return const string
		*/
		const string get_snapshot_id();
		/// Setter for the private variable snapshot_id
		/**
			\param snapshot_id_ : snapshot id to be deleted(unique for each snapshot)
		*/
		void set_snapshot_id(string snapshot_id_);
	};
}
#endif

