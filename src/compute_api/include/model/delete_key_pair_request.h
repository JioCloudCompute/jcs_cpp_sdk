#ifndef DELETE_KEY_PAIR_H
#define DELETE_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle delete key pair request
	/**
		This class manages the request for delete key pair. User can create an object and and initialize the needed arguments.
	*/
	class delete_key_pair_request
	{
	private:
		string key_name;

	public:
		/// Constructor
		delete_key_pair_request();
		/// Getter for the private variable key_name
		/**
			\return const string
		*/
		const string get_key_name();
		/// Setter for the private variable key_name
		/**
			\param key_name_ : key name to be deleted(unique for each key)
		*/
		void set_key_name(string key_name_);
	};
}
#endif

