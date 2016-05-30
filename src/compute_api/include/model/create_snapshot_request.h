#ifndef CREATE_SNAPSHOT_H
#define CREATE_SNAPSHOT_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle create snaphot request
	/**
		This class manages the request for create snaphot. User can create an object and and initialize the needed arguments.
	*/
	class create_snapshot_request
	{
	private:
		string volume_id;

	public:
		/// Constructor
		create_snapshot_request();
		/// Getter for the private variable volume_id
		/**
			\return const string
		*/
		const string get_volume_id() const;
		/// Setter for the private variable volume_id
		/**
			\param volume_id_ : volume id of the volume for hich snapshot will be created(unique for each volume)
		*/
		void set_volume_id(const string& volume_id_);
	};
}
#endif

