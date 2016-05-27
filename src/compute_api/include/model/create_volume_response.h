#ifndef CREATE_VOLUMER_H
#define CREATE_VOLUMER_H
#include <string>
using namespace std;
namespace model
{
	/// Class to handle Create Volume Request's Response.
	/**
		This class object describes the volume created
	*/
	class create_volume_response
	{
	private:
		string request_id;
		string status;
		string volume_id;
		string snapshot_id;
		float size;
		string create_time;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		create_volume_response(const string &xml_doc);
		create_volume_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id()
		{
			return request_id;
		}
		///Getter for the Status of the volume created
		/**
			\return const string
		*/
		const string get_status()
		{
			return status;
		}
		///Getter for the ID of the volume created
		/**
			\return const string
		*/
		const string get_volume_id()
		{
			return volume_id;
		}
		///Getter for the ID of the snapshot to which the volume is attached
		/**
			\return const string
		*/
		const string get_snapshot_id()
		{
			return snapshot_id;
		}
		///Getter for the Size of the Volume Created
		/**
			\return float
		*/
		const float get_size()
		{
			return size;
		}
		///Getter for the time Volume was created
		/**
			\return const string
		*/
		const string get_create_time()
		{
			return create_time;
		}

	};
}
#endif

