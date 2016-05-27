#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include <string>
using namespace std;

namespace model
{
	///Class to Handle Snapshot Object
	class snapshot
	{
	private:
		string status;
		string snapshot_id;
		float volume_size;
		string volume_id;
		string start_time;

	public:
		///Constructor
		snapshot(string status_, string snapshot_id_, float volume_size_, string volume_id_, string start_time_)
		{
			status = status_;
			snapshot_id = snapshot_id_;
			volume_size = volume_size_;
			volume_id = volume_id_;
			start_time = start_time;
		}
		snapshot(){}
		///Getter for the Snapshot ID of the snapshot
		/**
			\return const string
		*/
		const string get_snapshot_id()
		{
			return snapshot_id;
		}
		///Getter for the Volume ID 
		/**
			\return const string
		*/

		const string get_volume_id()
		{
			return volume_id;
		}

		///Getter for the current Status of the Snapshot
		/**
			\return const string
		*/
		const string get_status()
		{
			return status;
		}
		///Getter for the Volume Size of the Snapshot
		/**
			\return const float
		*/
		const float get_volume_size()
		{
			return volume_size;
		}
		///Getter for the start time of the Snapshot
		/**
			\return const string 
		*/
		const string get_start_time()
		{
			return start_time;
		}
	};
}
#endif
