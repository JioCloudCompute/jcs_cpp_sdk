#ifndef DESCRIBE_KEYR_H
#define DESCRIBE_KEYR_H
#include <string>
#include <map>
#include "src/compute_api/include/model/key_pair.h"
using namespace std;
using namespace model;

namespace model
{	/// Class to handle Describe Key Pairs Request Respones
	/**
		This Response Class has member functions that returns the description of Key Pairs that are created by the user.  
	*/
	class describe_key_pairs_response
	{
	private:
		string request_id;
		vector<model::key_pair>key_pairs;
	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		describe_key_pairs_response(const string &xml_doc);
		describe_key_pairs_response(){}
		///Getter for the Description of Key Pairs created by the authentic user.
		/**
			\return const vector<model::key_pair>  
			A vector of objects of class key_pair
		*/
		const vector<model::key_pair> get_key_pairs() const
		{
			return key_pairs;
		}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
	};
}
#endif

