#ifndef VOLUME_H
#define VOLUME_H
#include <string>
#include <map>
using namespace std;

namespace model
{
	///Class to Handle Volume Oject
	class volume
	{
	private:
		string status;
		string volume_id;
		string device;
		string instance_id;
		string snapshot_id;
		string create_time;
		float size;

	public:
		///Constructor
		volume(string status_, string volume_id_, string device_, string instance_id_, string snapshot_id_, string create_time_, float size_)
		{
			status = status_;
			volume_id = volume_id_;
			device = device_;
			instance_id = instance_id_;
			snapshot_id = snapshot_id_;
			create_time = create_time_;
			size = size_;

		}

		volume(){}
		///Getter for the Current Status of the Volume Object
		/**
			\return const string
		*/
		const string get_status()
		{
			return status;
		}
		///Getter for the current volume ID
		/**
			\return const string
		*/
		const string get_volume_id()
		{
			return volume_id;
		}
		///Getter for the Device ID of the Volume Storage
		/**
			\return const string
		*/
		const string get_device()
		{
			return device;
		}
		///Getter for the Instance ID to which the Volume is attached
		/**
			return const string
		*/
		const string get_instance_id()
		{
			return instance_id;
		}
		///Getter for the Snapshot ID 
		/**
			\return const string
		*/
		const string get_snapshot_id()
		{
			return snapshot_id;
		}
		///Getter for the Create Time of the Volume
		/**
			\return const string
		*/
		const string get_create_time()
		{
			return create_time;
		}
		///Getter for the Size of the Volume
		/**
			\return const float
		*/
		const float get_size()
		{
			return size;
		}

	};
}
#endif
