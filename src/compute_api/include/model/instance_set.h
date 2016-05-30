#ifndef INSTANCE_SET_H
#define INSTANCE_SET_H
#include <string>
using namespace std;

namespace model
{	///Class Describing the Details of a Instance
	/**
		
	*/
	class instance_set
	{
	private:
		string instance_id;
		string current_state;
		string previous_state;
	public:
		///Constructor
		
		instance_set(string instance_id_, string current_state_, string previous_state_)
		{
			instance_id = instance_id_;
			current_state = current_state_;
			previous_state = previous_state_;
		}
		instance_set(){}
		///Getter for the Instance ID
		/**
			\return const string
		*/
		const string get_instance_id() const
		{
			return instance_id;
		}
		///Getter for the Current State of the Instance
		/**
			\return const string
			pending, running, shutting-down, terminated, stopping, stopped
		*/

		const string get_current_state() const
		{
			return current_state;
		}
		///Getter for the Previous State of the Instance
		/**
			\return const string
			pending, running, shutting-down, terminated, stopping, stopped
		*/
		const string get_previous_state() const
		{
			return previous_state;
		}
	};
}
#endif
