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
#ifndef COMPUTEM_H
#define COMPUTEM_H

#include "requestify.hpp"
#include "config.hpp"
#include "utils.hpp"
#include "image.hpp"
#include "instance.hpp"
#include "volume.hpp"
#include "snapshot.hpp"
#include "key_pair.hpp"
#include "model/error_response.hpp"


namespace JIOCOMPUTE{
	class compute
	{
		utils::auth_var info;

		public:
		///Constructor
		/**
			Initializes the compute endpoint url, Type of HTTP request, Version
		*/
		compute(const std::string& url, const std::string& access_key, const std::string& secret_key, bool is_secure=true);


    void set_timeout(int timeout_in_secs);
    void set_retry(int retry_count);

		///Method to get info of the requested images 
		/**
			\param req : Type describe_images_request object 
			\return describe_images_response object pointer
		*/
		describe_images_response *describe_images(const describe_images_request &req);
		///Method to get info of the requested or all instances
		/**
			\param req : Type describe_instances_request object
			\return describe_instances_response object poinrer
		*/
		describe_instances_response *describe_instances(const describe_instances_request &req);
		///Method to get info of types of instances
		/**
			\param req : Type describe_instances_request 
			\return describe_instances_response object pointer
		*/
		describe_instance_types_response *describe_instance_types(const describe_instance_types_request &req);
		///Method to start requested instances
		/**
			\param req : Type start_instances_request
			\return start_instances_response object pointer
		*/
		start_instances_response *start_instances(const start_instances_request &req);
		///Method to stop requested instances
		/**
			\param req : Type stop_instances_request 
			\return stop_instances_response object pointer
		*/
		stop_instances_response *stop_instances(const stop_instances_request &req);
		///Method to reboot requested instances
		/**
			\param req : Type reboot_instances_request
			\return reboot_instance_response object pointer
		*/
		reboot_instances_response *reboot_instances(const reboot_instances_request &req);
		///Method to terminate requested instances
		/**
			\param req : Type terminate_instances_request 
			\return terminate_instances_response objedt pointer
		*/
		terminate_instances_response *terminate_instances(const terminate_instances_request &req);
		///Method to create instances
		/**
			\param req : Type run_instances_request
			\return run_instances_response object pointer
		*/
		run_instances_response *run_instances(const run_instances_request &req);
		///Method to get info of all key pairs
		describe_key_pairs_response *describe_key_pairs();
		///Method to create a Key Pair
		/**
			\param req : Type create_key_pair_request
			\return create_key_pair_response object pointer
		*/
		create_key_pair_response *create_key_pair(const create_key_pair_request &req);
		///Method to delete a Key Pair
		/**
			\param req : Type delete_key_pair_request
			\return delete_key_pair_response object pointer
		*/
		delete_key_pair_response *delete_key_pair(const delete_key_pair_request &req);
		///Method to Import Key Pair
		/**
			\param req : Type import_key_pair_request
			\return import_key_pair_response object POinter
		*/
		import_key_pair_response *import_key_pair(const import_key_pair_request &req);
		///Method to get info of all / requested Snapshots
		/**
			\param req : Type describe_snapshots_request 
			\return describe_snapshots_response object Pointer
		*/
		describe_snapshots_response *describe_snapshots(const describe_snapshots_request &req);
		///Methode to create a Snapshot
		/**
			\param req : Type create_snapshot_request
			\return create_snapshot_response object pointer
		*/	
		create_snapshot_response *create_snapshot(const create_snapshot_request &req);
		///Method to delete a snapshot
		/**
			\param req : Type delete_snapshot_request
			\return delete_snapshot_response object pointer
		*/
		delete_snapshot_response *delete_snapshot(const delete_snapshot_request &req);
		///Method to describe all/requested volumes
		/**
			\param req : describe_volumes_request
			\return describe_volumes_response objec pointer
		*/	
		describe_volumes_response *describe_volumes(const describe_volumes_request &req);
		///Method to create Volumes
		/**
			\param req : Type create_volume_request
			\return create_volume_response object pointer
		*/
		create_volume_response *create_volume(const create_volume_request &req);
		///Method to delete volume 
		/**
			\param req : Type delete_volume_request
			\return delete_volume_response object pointer
		*/
		delete_volume_response *delete_volume(const delete_volume_request &req);
		///Method to attach volume
		/**
		*/
		attach_volume_response *attach_volume(const attach_volume_request &req);
		///Method to detach volume
		/**
		*/
		detach_volume_response *detach_volume(const detach_volume_request &req);
		///Method to get info of the delete on termination flag of volume
		/**
		*/
		show_delete_on_termination_flag_response *show_delete_on_termination_flag(const show_delete_on_termination_flag_request &req);
		///Method to update delet on termination flag of a respictive volume
		/**
		*/
		update_delete_on_termination_flag_response *update_delete_on_termination_flag(const update_delete_on_termination_flag_request &req);
		///Method to get password data of the requested instance
		/**
		*/
		get_password_data_response *get_password_data(const get_password_data_request &req);	

		
	};

}

#endif
