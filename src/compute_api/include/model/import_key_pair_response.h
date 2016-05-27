#ifndef IMPORT_KEY_PAIRR_H
#define IMPORT_KEY_PAIRR_H
#include <string>
using namespace std;
namespace model
{
	/// Class to handle Import Key Pair Request's Response
	/**
		This Response Class has member functions that returns description of the Key pair Imported  
	*/
	class import_key_pair_response
	{
	private:
		string request_id;
		model ::key_pair key;
	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		import_key_pair_response(const string &xml_doc);
		///Getter for the Description of the key pair
		/**
			\return const vector<key_pair>
			A vector of objects of class key_pair
		*/
		const model::key_pair get_key()
		{
			return key;
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

