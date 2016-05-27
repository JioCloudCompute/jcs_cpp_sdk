#ifndef INSTANCE_TYPE_H
#define INSTANCE_TYPE_H
#include <string>
using namespace std;

namespace model
{	///Class to handle Instance Type

	class instance_type
	{
	private:
		float vcpus;
		float ram;
		string id;
	public:
		///Constructor
		instance_type(float vcpus_, float ram_, string id_)
		{
			vcpus = vcpus_;
			ram = ram_;
			id = id_;
		}
		instance_type(){}
		///Getter for the VC Pus of the Instance
		/**
			\return const float
		*/
		const float get_vcpus()
		{
			return vcpus;
		}
		///Getter for the Ram of the Instance
		/**
			\return const float
		*/
		const float get_ram()
		{
			return ram;
		}
		///Getter for the ID of the Instance
		/**
			\return const string
		*/
		const string get_id()
		{
			return id;
		}
	};
}
#endif
