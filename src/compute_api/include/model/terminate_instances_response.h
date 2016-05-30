#ifndef TERMINATE_INSTANCER_H
#define TERMINATE_INSTANCER_H
#include <string>
#include <map>
#include "src/compute_api/include/model/instance_set.h"
using namespace std;
using namespace model;

namespace model
{
	/// Class to handle Terminate Instance Request's Response
	/**
		This Response Class has member functions that returns the description of the Instances requested to Terminate.  
	*/
	class terminate_instances_response
	{
	private:
		string request_id;
		vector<model::instance_set> instances;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		terminate_instances_response(const string &xml_doc);
		terminate_instances_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of the instances that were terminated
		/**
			\return const vector<model::instance_set>
			A vector of objects of class instance_set
		*/
		const vector<model::instance_set> get_instances() const
		{
			return instances;
		}

	};
}
#endif
