#ifndef DESCRIBE_VOLUMES_H
#define DESCRIBE_VOLUMES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle describe snapshots request
	/**
		This class manages the request for describe snapshots. User can create an object and and initialize the needed arguments.
	*/
	class describe_volumes_request
	{
	private:
		vector<string> volume_ids;
		int max_results;
		string next_token;
		bool detail;

	public:
		/// Constructor
		describe_volumes_request();
		/// Getter for the private variable volume_id
		/**
			\return const vector<string> *
		*/
		const vector<string> *get_volume_ids();
		/// Setter for the private variable volume_id
		/**
			\param volume_set (optional): reference to a vector of volume ids
		*/
		void set_volume_ids(vector<string> volume_id_set);

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

