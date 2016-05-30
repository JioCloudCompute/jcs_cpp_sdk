#ifndef ATTACH_VOLUME_H
#define ATTACH_VOLUME_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle attach volume request
	/**
		This class manages the request for attach volume. User can create an object and and initialize the needed arguments.
	*/
	class attach_volume_request
	{
	private:
		string instance_id;
		string volume_id;
		string device;

	public:
		/// Constructor
		attach_volume_request();

		/// Getter for the private variable instance_id
		/**
			\return const string
		*/ 
		const string get_instance_id() const;

		/// Setter for the private variable instance_id 
		/**
			\param instance_id_ : instance id  with which volume will be attached(unique for each instance)
		*/
		void set_instance_id(const string& instance_id_);

		/// Getter for the private variable volume_id 
		/**
			\return const string
		*/
		const string get_volume_id() const;

		/// Setter for the private variable volume
		/**
			\param volume_id_ : volume id which will be attached(unique for each volume)
		*/
		void set_volume_id(const string& volume_id_);

		/// Getter for the private variable device 
		/**
			\return const string
		*/
		const string get_device() const;

		/// Setter for the private variable device 
		/**
			\param device_ : device where the vlume will be attached(/dev/vdb, /dev/vdc)
		*/
		void set_device(const string& device_);


	};
}
#endif

