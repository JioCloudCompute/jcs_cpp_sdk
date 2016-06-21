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
#ifndef CONFIG
#define CONFIG
#include <string>
// TODO :read from configuration files or hard COde >??
namespace config{
	//void set_up_endpoints();
	std::string get_service_url(std::string service_name);


	class ConfigHandler
	{
		private:
			//endpoints already
			bool secure;	// Whether the HTTP connection is secure
			bool debug;		// Debug mode

			// read this from config file 
			std::string access_key;	
			std::string secret_key;
			
		public:
			ConfigHandler();
			// Getter for access Key
			std::string get_access_key() const;
			//Getter for secret Key
			std::string get_secret_key() const;
			bool check_secure() const;
			bool check_debug() const;


	};

}
#endif