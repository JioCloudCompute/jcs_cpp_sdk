#ifndef SHOW_DELETER_H
#define SHOW_DELETER_H
#include <string>
using namespace std;
namespace model
{
	/// Class to handle Show Delete On Termination Flag Request's Response
	/**
		This Response Class has member functions that returns the description of the volume whose flag is requested .  
	*/
	class show_delete_on_termination_flag_response
	{
	private:
		string request_id;
		string instance_id;
		string volume_id;
		bool delete_on_termination;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		show_delete_on_termination_flag_response(const string &xml_doc);
		show_delete_on_termination_flag_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for the Instance ID to which the volume is attached
		/**
			\return const string
		*/
		const string get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the Volume ID
		/**
			\return const string
		*/
		const string get_volume_id() const
		{
			return volume_id;
		}
			///Getter for the Delete On termination Flag corresponding to the Volume
		/**
			\return const bool
		*/
		const bool get_delete_on_termination() const
		{
			return delete_on_termination;
		}

	};
}
#endif
