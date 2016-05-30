#ifndef CREATE_KEY_PAIR_H
#define CREATE_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle create key pair request
	/**
		This class manages the request for create key pair. User can create an object and and initialize the needed arguments.
	*/
	class create_key_pair_request
	{
	private:
		string key_name;

	public:
		/// Constructor
		create_key_pair_request();
		/// Getter for the private variable key_name
		/**
			\return const string
		*/ 
		const string get_key_name() const;
		/// Setter for the private variable key_name
		/**
			\param key_name_ : key name of the key pair created (unique for each key pair)
		*/ 
		void set_key_name(const string& key_name_);
	};
}
#endif

