#ifndef DESCRIBE_IMAGES_H
#define DESCRIBE_IMAGES_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle describe images request
	/**
		This class manages the request for describe images. User can create an object and and initialize the needed arguments.
	*/
	class describe_images_request
	{
	private:
		vector<string> image_ids;

	public:
		/// Constructor
		describe_images_request();
		/// Getter for the private variable image_ids
		/**
			\return const vector<string> *
		*/
		const vector<string>* get_image_ids() const;
		/// Setter for the private variable image_ids
		/**
			\param image_id_set (optional) : reference to a vector of image ids for which description is needed
		*/
		void set_image_ids(const vector<string> &image_id_set);
	};
}

#endif
