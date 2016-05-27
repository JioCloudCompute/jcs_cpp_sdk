#ifndef CREATE_SNAPSHOTR_H
#define CREATE_SNAPSHOTR_H
#include <string>
using namespace std;
namespace model
{
	/// Class to handle Create Snapshot Request's Response
	/**
		This Response Class has member variables and functions to get details of
		the snapshot that was created.
	*/
	class create_snapshot_response
	{
	private:
		string request_id;
		string status;
		string snapshot_id;
		float volume_size;
		string volume_id;
		string start_time;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		create_snapshot_response(const string &xml_doc);
		create_snapshot_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id()
		{
			return request_id;
		}
		///Getter for the Status of the Snapshot created
		/**
			\return const string
		*/
		const string get_status()
		{
			return status;
		}
		///Getter for the ID of the snapshot created
		/**
			\return const string
		*/
		const string get_snapshot_id()
		{
			return snapshot_id;
		}
		///Getter for the Volume Size attached with the Snapshot created
		/**
			\return float
		*/
		const float get_volume_size()
		{
			return volume_size;
		}
		///Getter for the Volume ID attached with the Snapshot created
		/**
			\return const string
		*/
		const string get_volume_id()
		{
			return volume_id;
		}
		///Getter for the time Snapshot was created
		/**
			\return const string
		*/
		const string get_start_time()
		{
			return start_time;
		}

	};
}
#endif

