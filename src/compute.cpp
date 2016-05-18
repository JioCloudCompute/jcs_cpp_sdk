#include "compute_api/image.cpp"
#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;

class compute{
	http_var info;
public:
	compute()
	{
		strcpy(info.url, "https://compute.ind-west-1.staging.jiocloudservices.com");
		strcpy(info.verb, "GET");
		strcpy(info.headers, "");
		strcpy(info.version, "2016-03-01");
	}

	string describe_images(vector<string>image_ids)
	{
		string result;
		result = ::describe_images(info);
		return result;
	}
};

int main(){
	compute obj;
	string result;
	vector<string>image_ids;
	result = obj.describe_images(image_ids);	
	cout<<"final result <<< "<<result<<endl;
	return 0;
}