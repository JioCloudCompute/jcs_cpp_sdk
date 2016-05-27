#ifndef DETACH_VOLUMER_H
#define DETACH_VOLUMER_H
#include <string>
using namespace std;
namespace model
{	
	/// Class to handle Detach Volume Request's Response
	/**
		This Response Class has member functions that returns the description of the Volume requested to detach.  
	*/
	class detach_volume_response
	{
	private:
		string request_id;
		string device;
		string instance_id;
		bool delete_on_termination;
		string status;
		string volume_id;
	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		detach_volume_response(const string &xml_doc);
		detach_volume_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() 
		{
			return request_id;
		}
		///Getter for the Current Status of the Volume
		/**
			\return const string
		*/
		const string get_status()
		{
			return status;
		}
		///Getter for the Device Name of the Volume
		/**
			\return const string
		*/
		const string get_device()
		{
			return device;
		}
		///Getter for the instance ID from which the volume got Dettached
		/**
			\return const string
		*/
		const string get_instance_id()
		{
			return instance_id;
		}
		///Getter for the Volume ID
		/**
			\return const string
		*/
		const string get_volume_id()
		{
			return  volume_id;
		}
		///Getter for the Delete On termination Flag
		/**
			\return const bool
			True if volume get's Deleted** on Termination of the instance to which the it is attached
		*/
		const bool get_delete_on_termination()
		{
			return delete_on_termination;
		}
	};

}
#endif

