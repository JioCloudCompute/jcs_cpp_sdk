#ifndef REBOOT_INSTANCE_H
#define REBOOT_INSTANCE_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle reboot instances request
	/**
		This class manages the request for reboot instances. User can create an object and and initialize the needed arguments.
	*/
	class reboot_instances_request
	{
	private:
		vector<string> instance_ids;

	public:
		/// Constructor
		reboot_instances_request();
		/// Getter for the private variable instance_ids
		/**
			\return const vector<string> *
		*/
		const vector<string> *get_instance_ids();
		/// Setter for the private variable instance_ids
		/**
			\param instance_id_set (optional): reference to a vector of instance ids
		*/
		void set_instance_ids(vector<string>instance_id_set);
	};
}
#endif
