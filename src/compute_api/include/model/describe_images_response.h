#ifndef DESCRIBE_IMAGESR_H
#define DESCRIBE_IMAGESR_H
#include "image.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

namespace model
{	
	/// Class to handle Describe Image Request's Response
	/**
		This Response Class has member functions that returns the description of images requested.
	*/
	class describe_images_response
	{

		vector<image> images;
		string request_id;
		public:
		/// Constructor
		/**
			This parses the XML_response of the API and sets the private member variables
		*/		
		describe_images_response(const string &xml_doc);
		describe_images_response(){}
		///Getter for the Unique Request ID
		/**
			\return const string
		*/
		string get_request_id()
		{
			return request_id;
		}
		///Getter for the Description of Images requested
		/**
			\return vector<image> 
			A vector of objects of class image
		*/
		vector<image> get_images() const
		{
			return images;
		}
	};
}
#endif
