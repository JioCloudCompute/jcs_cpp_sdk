#Overview
##C++ SDK for JCS

###Installation

git clone https://github.com/jiocloudservices/jcsclient.git  
$ cd jcs_cpp_sdk/  
$ make setup (For installing libraries libcurl and openssl libraries)  
$ make  
$ make install (install static and shared library in /usr/lib)  
$ make doc (to create Documentation of the project)  
To view Documentation goto doc/html/index.html  

###Configuration  
  
Open config.txt and set access key, secret key, secure (1 to make secure connection), debug (1 for debug mode).  
Running the program in debug mode prints error messages for easy debugging  
  
Run the following commands everytime sdk is used. It is best to add the following commands in your bashrc.  
CPLUS_INCLUDE_PATH=<path to directory jcs_cpp_sdk>	
export CPLUS_INCLUDE_PATH  
  
NOTE: Never ever commit your access and secret keys and push to a public repository. You have been warned.  
  
###SDK  
  
While linking your cpp file or object file with library use "-lcompute" after the file  
**Eg:** g++ test.cpp -lcompute  
