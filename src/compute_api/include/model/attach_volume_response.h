#ifndef ATTACH_VOLUMER_H
#define ATTACH_VOLUMER_H
#include <string>
using namespace std;

//! Models of Request Object Sent and Response Recieved 
namespace model
{
	/// Class to handle Attach Volume Response
	/**
		This Response Class has member variables and functions to get details of
		the volume that was requested to attach to a particular instance. 
	*/
	class attach_volume_response
	{
	private:
		string request_id; /**<  String \n Unique Request ID of the reponse recieved */
		string device;/**<  String \n Device Name of the Volume Attached */
		string instance_id;/**<  String \n Instance ID to which the Volume was attached */
		bool delete_on_termination;/**<  Bool \n Flag describing whether the volume will be deleted on instance Termination */
		string status; /**<  String \n Status of the request to attach volume */
		string volume_id;/**<  String \n Unique Id of the volume that was requested to attach */
	public:
		/// Constructor for Attach Volume Response
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		attach_volume_response(const string &xml_doc);
		attach_volume_response(){}
		///Getter for the Request ID
		/**
			\return  String
		*/
		const string get_request_id() 
		{
			return request_id;
		}
		///Getter for the Status of the Request
		/**
			\return  String
		*/
		const string get_status()
		{
			return status;
		}
		///Getter for the Device Name
		/**
			\return  String
		*/
		const string get_device()
		{
			return device;
		}
		///Getter for the Instance ID
		/**
			\return  String
		*/
		const string get_instance_id()
		{
			return instance_id;
		}
		///Getter for the Volume Id
		/**
			\return  String
		*/
		const string get_volume_id()
		{
			return  volume_id;
		}
		///Getter for the Delete On Termination Flag 
		/**
			\return  Bool
		*/
		const bool get_delete_on_termination()
		{
			return delete_on_termination;
		}
	};

}
#endif

