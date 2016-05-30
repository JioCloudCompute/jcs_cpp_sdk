#ifndef DELETE_SNAPSHOTR_H
#define DELETE_SNAPSHOTR_H
#include <string>
using namespace std;
namespace model
{	
	/// Class to handle Delete Key Pair Request's Response
	/**
		This Response Class has member function to know whether the snapshot was deleted successfully. 
	*/
	class delete_snapshot_response
	{
	private:
		string request_id;
		bool result;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		delete_snapshot_response(const string &xml_doc);
		delete_snapshot_response(){}
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
			True if Snapshot was successfully Deleted
		*/
		const bool get_result() const
		{
			return result;
		}

	};
}
#endif

