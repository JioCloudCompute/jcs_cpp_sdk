#ifndef UPDATE_DELETER_H
#define UPDATE_DELETER_H
#include <string>
using namespace std;
namespace model
{
	class update_delete_on_termination_flag_response
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
		update_delete_on_termination_flag_response(const string &xml_doc);
		update_delete_on_termination_flag_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id()
		{
			return request_id;
		}
		///Getter for the Instance ID to which the volume is attached
		/**
			\return const string
		*/
		const string get_instance_id()
		{
			return instance_id;
		}
		///Getter for the Volume ID whose Flag has to be updated
		/**
			\return const string
		*/
		const string get_volume_id()
		{
			return volume_id;
		}
		///Getter for the Delete On termination Flag corresponding to the Volume
		/**
			\return const bool
		*/
		const bool get_delete_on_termination()
		{
			return delete_on_termination;
		}

	};
}
#endif
