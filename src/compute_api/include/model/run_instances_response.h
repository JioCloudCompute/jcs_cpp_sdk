#ifndef RUN_INSTANCESR_H
#define RUN_INSTANCESR_H
#include <string>
#include <map>
#include <src/compute_api/include/model/instance.h>

using namespace std;
using namespace model;
namespace model
{
	/// Class to handle Run Instance Request's Response
	/**
		This Response Class has member functions that returns the description of the Instances requested to run(create).  
	*/

	class run_instances_response{
	private:
		vector<instance> instances;
		string request_id;
	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		run_instances_response(const string &xml_doc);
		run_instances_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of the instances that were requested to run
		/**
			\return const vector<instance>
			A vector of objects of class instance
		*/
		const vector<instance> get_instances() const
		{
			return instances;
		}

	};

}
#endif

