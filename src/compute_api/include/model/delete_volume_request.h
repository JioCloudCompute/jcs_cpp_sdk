#ifndef DELETE_VOLUME_H
#define DELETE_VOLUME_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle delete volume request
	/**
		This class manages the request for delete volume. User can create an object and and initialize the needed arguments.
	*/
	class delete_volume_request
	{
	private:
		/// Constructor
		string volume_id;

	public:
		delete_volume_request();
		/// Getter for the private variable volume_id
		/**
			\return const string
		*/
		const string get_volume_id() const;
		/// Setter for the private variable volume_id
		/**
			\param volume_id_ : volume id  to be deleted(unique for each volume)
		*/
		void set_volume_id(const string& volume_id_);
	};
}
#endif

