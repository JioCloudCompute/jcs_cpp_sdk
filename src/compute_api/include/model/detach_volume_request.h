#ifndef DETACH_VOLUME_H
#define DETACH_VOLUME_H
#include <vector>
#include <string>

using namespace std;

namespace model
{	/// Class to handle detach volume request
	/**
		This class manages the request for detach volume. User can create an object and and initialize the needed arguments.
	*/
	class detach_volume_request
	{
	private:
		string instance_id;
		string volume_id;

	public:
		/// Constructor
		detach_volume_request();
		/// Getter for the private variable instance_id
		/**
			\return const string
		*/
		const string get_instance_id() const;
		/// Setter for the private variable instance_id
		/**
			\param instance_id_ (optional): instance id (unique for each instance)
		*/
		void set_instance_id(const string& instance_id_);
		/// Getter for the private variable volume_id
		/**
			\return const string
		*/
		const string get_volume_id() const;
		/// Setter for the private variable volume_id
		/**
			\param volume_id_ : volume id (unique for each volume)
		*/
		void set_volume_id(const string& volume_id_);

	};
}
#endif
