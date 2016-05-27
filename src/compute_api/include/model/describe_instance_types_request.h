#ifndef DESCRIBE_INSTANCES_TYPES_H
#define DESCRIBE_INSTANCES_TYPES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle describe instance types request
	/**
		This class manages the request for describe instance types. User can create an object and and initialize the needed arguments.
	*/
	class describe_instance_types_request
	{
	private:
		vector<string> instance_type_ids;

	public:
		/// Constructor
		describe_instance_types_request();
		/// Getter for the private variable instance_type_ids
		/**
			\return const vector<string> *
		*/
		const vector<string> *get_instance_type_ids();
		/// Setter for the private variable instance_type_ids
		/**
			\param instance_type_id_set (optional) : reference to a vector of instance type ids
		*/
		void set_instance_types_ids(vector<string>instance_type_id_set);
	};
}
#endif

