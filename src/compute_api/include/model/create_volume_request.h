#ifndef CREATE_VOLUME_H
#define CREATE_VOLUME_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle create volume request
	/**
		This class manages the request for create volume. User can create an object and and initialize the needed arguments.
	*/
	class create_volume_request
	{
	private:
		string snapshot_id;
		int size;

	public:
		/// Constructor
		create_volume_request();
		/// Getter for the private variable snapshot_id
		/**
			\return const string
		*/
		const string get_snapshot_id();
		/// Setter for the private variable snapshot_id
		/**
			\param snapshot_id_ (optional) : snapshot id to create volume similar to the volume from which snapshot is created(unique for each snapshot). Not necessary if size is given
		*/
		void set_snapshot_id(string snapshot_id_);
		/// Getter for the private variable size
		/**
			\return const string
		*/
		const int get_size();
		/// Setter for the private variable size
		/**
			\param size_(optional) : size of the volume. Not necessary if snapshot id is given
		*/
		void set_size(int size_);
	};
}
#endif
