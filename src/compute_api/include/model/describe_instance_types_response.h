#ifndef DESCRIBE_INSTANCE_TYPESR_H
#define DESCRIBE_INSTANCE_TYPESR_H
#include <map>
#include "src/compute_api/include/model/instance_type.h"
using namespace std;
using namespace model;

namespace model
{	
	/// Class to handle Describe Instance Type Request's Response
	/**
		This Response Class has member functions that returns the description of instance types requested for.  
	*/
	class describe_instance_types_response
	{
	private:
		string request_id;
		vector<model::instance_type>instance_type_set;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		describe_instance_types_response(const string &xml_doc);
		describe_instance_types_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of Intance Types requested
		/**
			\return const vector<model::instance_type>  
			A vector of objects of class instance_type
		*/
		const vector<model::instance_type> get_instance_types() const
		{
			return instance_type_set;
		}
	};
}
#endif

