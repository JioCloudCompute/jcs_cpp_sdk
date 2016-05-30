#ifndef DESCRIBE_INSTANCES_H
#define DESCRIBE_INSTANCES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle describe instances request
	/**
		This class manages the request for describe instances. User can create an object and and initialize the needed arguments.
	*/
	class describe_instances_request
	{
	private:
		vector<string> instance_ids;

	public:
		/// Constructor
		describe_instances_request();
		/// Getter for the private variable instance_ids
		/**
			\return const vector<string> *
		*/
		const vector<string> *get_instance_ids() const;
		/// Setter for the private variable instance_ids
		/**
			\param instance_id_set (optional) : reference to a vector of instance ids
		*/
		void set_instance_ids(const vector<string>& instance_id_set);
	};
}
#endif

