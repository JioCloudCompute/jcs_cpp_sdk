#ifndef GET_PASSWORD_DATA_H
#define GET_PASSWORD_DATA_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle attach volume request
	/**
		This class manages the request for attach volume. User can create an object and and initialize the needed arguments.
	*/
	class get_password_data_request
	{
	private:
		string instance_id;
		string private_key_file;
		string passphrase;

	public:
		/// Constructor
		get_password_data_request(){}

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

		/// Getter for the private variable private_key_file
		/**
			\return const string
		*/
		const string get_private_key_file () const;

		/// Setter for the private variable private_key_file
		/**
			\param private_key_file_ (optional): path to the private key file
		*/
		void set_private_key_file(const string& private_key_file_);

		/// Getter for the private variable passphrase 
		/**
			\return const string
		*/
		const string get_passphrase() const;

		/// Setter for the private variable passphrase 
		/**
			\param passphrase_ (optional): password if the private key file is password protected
		*/
		void set_passphrase(const string& passphrase_);


	};
}
#endif

