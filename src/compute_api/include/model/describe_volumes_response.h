#ifndef DESCRIBE_VOLUMESR_H
#define DESCRIBE_VOLUMESR_H
#include <map>
#include "src/compute_api/include/model/volume.h"
using namespace std;
using namespace model;

namespace model
{	
	/// Class to handle Describe Volume Request's Response
	/**
		This Response Class has member functions that returns the description of the Volumes requested.  
	*/
	class describe_volumes_response
	{
	private:
		string request_id;
		vector< model::volume>volume_set;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		describe_volumes_response(const string &xml_doc);
		describe_volumes_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of Volumes Requested
		/**
			\return const vector<model::volume>  
			A vector of objects of class volume
		*/
		const vector<model::volume> get_volume_set() const
		{
			return volume_set;
		}
	};
}
#endif
