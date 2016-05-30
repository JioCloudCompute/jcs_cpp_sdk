#ifndef INSTANCE_H
#define INSTANCE_H
#include <vector>
#include <string>
#include <map>
#include "block_device_instance.h"

using namespace std;
namespace model
{	///Class Describing Details of Instance
	class group_set
	{
	public:
		string group_name;
		string group_id;
	};

	class instance{
	private:
		
		vector<block_device_instance> block_devices;
		string dns_name;
		string instance_id;
		string instance_state;  //STATE definition
		string image_id;
		string private_dns_name;
		string key_name;

		string launch_time;
		string subnet_id;
		vector< group_set > group;
		string vpc_id;
		string instance_type;
		string private_ip_address;
	public:
		instance(){}

		///Constructor 
		/**
			This constructor is used to instantiate instances objects from the response of decribe instances request

		*/
		// Constructor used by describe_instances_response
		instance(vector<block_device_instance> block_devices_, string dns_name_ , string instance_id_, string instance_state_, string image_id_, string private_dns_name_, string key_name_,
				string launch_time_, string subnet_id_, vector<group_set>group_ ,string vpc_id_, string instance_type_, string private_ip_address_)
		{
			block_devices = block_devices_;
			dns_name = dns_name_;
			instance_id = instance_id_;
			instance_state = instance_state_;
			image_id = image_id_;
			private_dns_name_ = private_dns_name_;
			key_name = key_name_;
			launch_time = launch_time_;
			subnet_id = subnet_id_;
			group = group_;
			vpc_id = vpc_id_;
			instance_type = instance_type_;
			private_ip_address = private_ip_address_;
		}
		///Constructor 
		/**
			This constructor is used to instantiate instances objects from the response of run instances request
		*/
		// Constructor used by run_instances_response
		instance(string vpc_id_, string dns_name_ , string instance_id_, string instance_state_, string image_id_, string private_dns_name_, string key_name_,
				string launch_time_, string subnet_id_, vector<group_set>group_ , string instance_type_, string private_ip_address_)
		{
			dns_name = dns_name_;
			instance_id = instance_id_;
			instance_state = instance_state_;
			image_id = image_id_;
			private_dns_name_ = private_dns_name_;
			key_name = key_name_;
			launch_time = launch_time_;
			subnet_id = subnet_id_;
			group = group_;
			vpc_id = vpc_id_;
			instance_type = instance_type_;
			private_ip_address = private_ip_address_;
		}
		///Getter for the DNS Name 
		/**
			\return const string
		*/		
		const string get_dns_name() const
		{
			return dns_name;
		}
		///Getter for the Unique Instance ID of the instance
		/**
			\return const string
		*/
		const string get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the State of the instance
		/**
			\return const string
		*/
		const string get_instance_state() const
		{
			return instance_state;
		}
		///Getter for the Image Id to which the Instance belongs
		/**
			\return const string
		*/
		const string get_image_id() const
		{
			return image_id;
		}
		///Getter for the Private DNS Name
		/**
			\return const string
		*/
		const string get_private_dns_name() const
		{
			return private_dns_name;
		}
		const string get_key_name() const
		{
			return key_name;
		}
		///Getter for the Launch Time of the Instance
		/**
			\return const string
		*/
		const string get_launch_time() const
		{
			return launch_time;
		}
		///Getter for the Subet ID to which the Instance belongs
		/**
			\return const string
		*/
		const string get_subnet_id() const
		{
			return subnet_id;
		}
		///Getter for the Groups to which instance belongs to.
		/**
			\return const vector<group>
			A vector of objects of class group_set
		*/
		const vector<group_set> get_group() const
		{
			return group;
		}
		///Getter for the VPC ID of the Instance
		/**
			\return const string
		*/
		const string get_vpc_id() const
		{
			return vpc_id;
		}
		///Getter for the Type of the Instance
		/**
			\return const string
		*/
		const string get_instance_type() const
		{
			return instance_type;
		}
		///Getter for the Private IP address of the Instance
		/**
			\return const string
		*/
		const string get_private_ip_address() const
		{
			return private_ip_address;
		}
	};
}
#endif

