#ifndef DESCRIBE_INSTANCESR_H
#define DESCRIBE_INSTANCESR_H
#include <string>
#include <map>
#include <src/compute_api/include/model/instance.h>

using namespace std;
using namespace model;
namespace model
{	
	/// Class to handle Describe Image Request's Response
	/**
		This Response Class has member functions that returns the description of instances requested for.  
	*/
	class describe_instances_response{
	private:
		vector<instance> instances;
		string request_id;
	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		describe_instances_response(const string &xml_doc);
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of Intances requested
		/**
			\return const vector<model::instance>  
			A vector of objects of class instance
		*/
		const vector<model::instance> get_instances() const
		{
			return instances;
		}

	};

}
#endif

