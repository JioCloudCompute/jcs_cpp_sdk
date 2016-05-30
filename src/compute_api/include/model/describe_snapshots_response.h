#ifndef DESCRIBE_SNAPSHOTSR_H
#define DESCRIBE_SNAPSHOTSR_H
#include <map>
#include "src/compute_api/include/model/snapshot.h"
using namespace std;
using namespace model;

namespace model
{
	/// Class to handle Describe Snapshots Request's Response
	/**
		This Response Class has member functions that returns the description of the Snapshots requested.  
	*/
	class describe_snapshots_response
	{
	private:
		string request_id;
		vector<model::snapshot>snapshot_set;

	public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/
		describe_snapshots_response(const string &xml_doc);
		describe_snapshots_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		const string get_request_id() const
		{
			return request_id;
		}
		///Getter for the Description of Snapshots
		/**
			\return const vector<model::snapshot>  
			A vector of objects of class snapshot
		*/
		const vector<model::snapshot> get_snapshot_set() const
		{
			return snapshot_set;
		}
	};
}
#endif

