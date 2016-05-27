#ifndef CREATE_KEY_PAIRR_H
#define CREATE_KEY_PAIRR_H
#include <string>
using namespace std;
namespace model
{
	/// Class to handle Create Key Pair Request's Response.
	/**
		This class object describes the key fingerprint, key material, key name of the created key pair.
	*/
	class create_key_pair_response
	{
	private:
		string key_fingerprint;
		string key_material;
		string key_name;
		string request_id;
	public:
		/// Constructor 
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		create_key_pair_response(const string &xml_doc);
		create_key_pair_response(){}

		///Getter for the Key FingerPrint of the Key Created
		/**
			\return const string
		*/
		const string get_key_fingerprint()
		{
			return key_fingerprint;
		}
		///Getter for the Key Material(RSA Private Key) of the Key Created
		/**
			\return const string
		*/
		const string get_key_material()
		{
			return key_material;
		}
		///Getter for the Key Name of the Key Created
		/**
			\return const string
		*/
		const string get_key_name()
		{
			return key_name;
		}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id()
		{
			return request_id;
		}
	};

}
#endif

