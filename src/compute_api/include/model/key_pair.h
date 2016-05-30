#ifndef KEY_PAIR_H
#define KEY_PAIR_H
#include <string>
using namespace std;
namespace model
{
	///Class To handle Key-Pair Object
	class key_pair
	{
	private:
		string key_name;
		string key_fingerprint;
	public:
		///Constructor
		key_pair(string key_name_, string key_fingerprint_)
		{
			key_name = key_name_;
			key_fingerprint = key_fingerprint_;
		}
		key_pair(){}
		///Getter for the Key-Name of the Key
		/**
			\return const string
		*/
		const string get_key_name() const
		{
			return key_name;
		}
		///Getter for the Key-FingerPrint of the Key
		/**
			\return const string
		*/
		const string get_key_fingerprint() const
		{
			return key_fingerprint;
		}
	};
}
#endif
