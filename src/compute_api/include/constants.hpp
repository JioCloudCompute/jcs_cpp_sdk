/*******************************************************************************
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
 *******************************************************************************/
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

using namespace std;
class constants 
{
public:
	static string ACTION;
	static string VERSION;

	static string ID;
	static string USER_ID;
	static string USER_NAME;
	static string GROUP_ID;
	static string GROUP_NAME;


	static string DESCRIBE_IMAGES;

	static string DESCRIBE_INSTANCES;
	static string DESCRIBE_INSTANCE_TYPES;
	static string RUN_INSTANCES;
	static string START_INSTANCES;
	static string STOP_INSTANCES;
	static string REBOOT_INSTANCES;
	static string TERMINATE_INSTANCES;
	static string GET_PASSWORD_DATA;

	static string CREATE_KEY_PAIR;
	static string DELETE_KEY_PAIR;
	static string DESCRIBE_KEY_PAIRS;
	static string IMPORT_KEY_PAIR;

	static string CREATE_SNAPSHOT;
	static string DELETE_SNAPSHOT;
	static string DESCRIBE_SNAPSHOTS;

	static string CREATE_VOLUME;
	static string DELETE_VOLUME;
	static string ATTACH_VOLUME;
	static string DETACH_VOLUME;
	static string DESCRIBE_VOLUMES;
	static string SHOW_DELETE_ON_TERMINATION_FLAG;
	static string UPDATE_DELETE_ON_TERMINATION_FLAG;

	static string IMAGE_ID;
	static string INSTANCE_ID;
	static string INSTANCE_TYPE_ID;
	static string VOLUME_ID;
	static string SNAPSHOT_ID;
	static string MAX_RESULTS;
	static string NEXT_TOKEN;
	static string DETAIL;
	static string SIZE;
	static string DEVICE;
	static string DELETE_ON_TERMINATION;
	static string KEY_NAME;
	static string PUBLIC_KEY_MATERIAL;
	static string DEVICE_NAME;
	static string VOLUME_SIZE;
	static string INSTANCE_COUNT;
	static string SUBNET_ID;
	static string PRIVATE_IP_ADDRESS;
	static string SECURITY_GROUP_ID;
	static string BLOCK;
};
#endif