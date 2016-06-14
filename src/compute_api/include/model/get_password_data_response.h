#ifndef GET_PASSWORD_H
#define GET_PASSWORD_H
#include <string>
using namespace std;

namespace model
{
	/// Class to handle Get Password Request's Response
	/**
	*/
	class get_password_data_response
	{
	private:
		string request_id;
		string password_data;
		string instance_id;
		string timestamp;
	public:
		/// Constructor for Get Password Data Response
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		get_password_data_response(const string &xml_doc);
		get_password_data_response(){}
		///Getter for the Request ID
		/**
			\return  String
		*/
		const string get_request_id() const 
		{
			return request_id;
		}
		///Getter for the Password Data
		/**
			\return  String
		*/
		const string get_password_data() const
		{
			return password_data;
		}
		///Getter for the Instance ID
		/**
			\return  String
		*/
		const string get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the time stamp
		/**
			\return  String
		*/
		const string get_timestamp() const
		{
			return  timestamp;
		}

		void set_data(string password_data)
		{
			this->password_data=password_data;
		}	

	};

}
#endif

