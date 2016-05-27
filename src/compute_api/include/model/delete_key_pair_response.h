#ifndef DELETE_KEY_PAIRR_H
#define DELETE_KEY_PAIRR_H
#include <string>
using namespace std;
namespace model
{	
	/// Class to handle Delete Key Pair Request's Response
	/**
		This Response Class has member function to know whether the key was successfully deleted or not. 
	*/
	class delete_key_pair_response
	{
	private:
		bool result;
		string request_id;
	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		delete_key_pair_response(const string &xml_doc);
		delete_key_pair_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id()
		{
			return request_id;
		}
		///Getter for Result of the Request
		/**
			\return bool
			True if Key Pair was successfully Deleted
		*/
		const bool get_result()
		{
			return result;
		}

	};
}
#endif

