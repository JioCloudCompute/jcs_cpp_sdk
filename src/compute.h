#ifndef COMPUTE_H
#define COMPUTE_H

#include "src/requestify.cpp"
#include "src/compute_api/source/image.cpp"
#include "src/compute_api/source/instance.cpp"
#include "src/compute_api/source/volume.cpp"
#include "src/compute_api/source/snapshot.cpp"
#include "src/compute_api/source/key_pair.cpp"
#include "src/compute_api/source/model/error_response.cpp"
#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;
using namespace image;
using namespace instance;
using namespace snapshot;
using namespace key_pair;
using namespace volume;
using namespace utils;
using namespace config;

namespace JIOCOMPUTE{
	class compute
	{
		utils::http_var info;

		public:
			
		compute();

		describe_images_response *describe_images(const describe_images_request &req);

		describe_instances_response *describe_instances(const describe_instances_request &req);
		
		describe_instance_types_response *describe_instance_types(const describe_instance_types_request &req);
		
		start_instances_response *start_instances(const start_instances_request &req);

		stop_instances_response *stop_instances(const stop_instances_request &req);

		reboot_instances_response *reboot_instances(const reboot_instances_request &req);

		terminate_instances_response *terminate_instances(const terminate_instances_request &req);

		run_instances_response *run_instances(const run_instances_request &req);

		describe_key_pairs_response *describe_key_pairs();

		create_key_pair_response *create_key_pair(const create_key_pair_request &req);

		delete_key_pair_response *delete_key_pair(const delete_key_pair_request &req);

		import_key_pair_response *import_key_pair(const import_key_pair_request &req);

		describe_snapshots_response *describe_snapshots(const describe_snapshots_request &req);

		create_snapshot_response *create_snapshot(const create_snapshot_request &req);

		delete_snapshot_response *delete_snapshot(const delete_snapshot_request &req);

		describe_volumes_response *describe_volumes(const describe_volumes_request &req);

		create_volume_response *create_volume(const create_volume_request &req);

		delete_volume_response *delete_volume(const delete_volume_request &req);

		attach_volume_response *attach_volume(const attach_volume_request &req);

		detach_volume_response *detach_volume(const detach_volume_request &req);

		show_delete_on_termination_flag_response *show_delete_on_termination_flag(const show_delete_on_termination_flag_request &req);

		update_delete_on_termination_flag_response *update_delete_on_termination_flag(const update_delete_on_termination_flag_request &req);
	

		
	};

}

#endif