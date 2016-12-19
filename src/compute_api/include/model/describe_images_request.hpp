/*****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
#ifndef DESCRIBE_IMAGES_H
#define DESCRIBE_IMAGES_H

#include <set>
#include <string>
#include <vector>

namespace model
{	/// Class to handle describe images request
	/**
		This class manages the request for describe images. User can create an object and and initialize the needed arguments.
	*/
	class describe_images_request
	{
	private:
    std::set<std::string> image_ids;

	public:
		/// Constructor
		describe_images_request();
		/// Getter for the private variable image_ids
		/**
			\return const vector<string> *
		*/
		const std::set<std::string>* get_image_ids() const;
		/// Setter for the private variable image_ids
		/**
			\param image_id_set (optional) : reference to a vector of image ids for which description is needed
		*/
		void set_image_ids(const std::vector<std::string>& image_id_set);

    /**
     * Add the image id to the request.
     * */
    void add_image_id(const std::string& image_id);

	};
}

#endif
