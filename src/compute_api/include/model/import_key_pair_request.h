#ifndef IMPORT_KEY_PAIR_H
#define IMPORT_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle import key pair request
	/**
		This class manages the request for import key pair. User can create an object and and initialize the needed arguments.
	*/
	class import_key_pair_request
	{
	private:
		string key_name;
		string public_key_material;

	public:
		/// Constructor
		import_key_pair_request();
		/// Getter for the private variable key_name
		/**
			\return const string
		*/
		const string get_key_name();
		/// Setter for the private variable key_name
		/**
			\param key_name_ : key name (unique for each key)
		*/
		void set_key_name(string key_name_);
		/// Getter for the private variable public_key_material
		/**
			\return const string
		*/
		const string get_public_key_material();
		/// Setter for the private variable public_key_material
		/**
			\param public_key_material_ : The public key contents creaed by a third party software. If not base64 encoded the public key material import would fail
		*/
		void set_public_key_material(string public_key_material_);
	};
}
#endif
