#ifndef DELETE_VOLUMER_H
#define DELETE_VOLUMER_H
#include <string>
using namespace std;
namespace model
{	
	/// Class to handle Delete Volume Request's Response
	/**
		This Response Class has member function to know whether the Volume was deleted successfully. 
	*/
	class delete_volume_response
	{
	private:
		string request_id;
		bool result;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		delete_volume_response(const string &xml_doc);
		delete_volume_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for Result of the Request
		/**
			\return bool
			True if Volume was successfully Deleted
		*/
		const bool get_result() const
		{
			return result;
		}

	};
}
#endif

