#ifndef DESCRIBE_SNAPSHOTS_H
#define DESCRIBE_SNAPSHOTS_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle describe snapshots request
	/**
		This class manages the request for describe snapshots. User can create an object and and initialize the needed arguments.
	*/
	class describe_snapshots_request
	{
	private:
		vector<string> snapshot_ids;
		int max_results;
		string next_token;
		bool detail;

	public:
		/// Constructor
		describe_snapshots_request();
		/// Getter for the private variable snapshots_id
		/**
			\return const vector<string> *
		*/
		const vector<string> *get_snapshot_ids();
		/// Setter for the private variable snapshots_id
		/**
			\param snapshot_id_set (optional): reference to a vector of snapshot ids
		*/
		void set_snapshot_ids(vector<string> snapshot_id_set);
		/// Getter for the private variable max_results
		/**
			\return const int
		*/
		const int get_max_results();
		/// Setter for the private variable max_results
		/**
			\param max_results_ (optional): Max number of results to be shown in response.
		*/
		void set_max_results(int max_results_);
		/// Getter for the private variable next_token
		/**
			\return const string
		*/
		const string get_next_token();
		/// Setter for the private variable next_token
		/**
			\param next_token_ (optional): NextToken - Id of last snapshot seen if max number of results is less than total snapshots
		*/
		void set_next_token(string next_token_);
		/// Getter for the private variable detail
		/**
			\return const bool
		*/
		const bool get_detail();
		/// Setter for the private variable detail
		/**
			\param detail_ (optional): Detail - by default this is true. Set to false to will supress detailed response
		*/
		void set_detail(bool detail_);

	};
}
#endif
