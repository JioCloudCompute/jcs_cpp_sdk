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
	static const string ACTION;
	static const string VERSION;

	static const string ID;
	static const string USER_ID;
	static const string USER_NAME;
	static const string GROUP_ID;
	static const string GROUP_NAME;


	static const string DESCRIBE_IMAGES;

	static const string DESCRIBE_INSTANCES;
	static const string DESCRIBE_INSTANCE_TYPES;
	static const string RUN_INSTANCES;
	static const string START_INSTANCES;
	static const string STOP_INSTANCES;
	static const string REBOOT_INSTANCES;
	static const string TERMINATE_INSTANCES;
	static const string GET_PASSWORD_DATA;

	static const string CREATE_KEY_PAIR;
	static const string DELETE_KEY_PAIR;
	static const string DESCRIBE_KEY_PAIRS;
	static const string IMPORT_KEY_PAIR;

	static const string CREATE_SNAPSHOT;
	static const string DELETE_SNAPSHOT;
	static const string DESCRIBE_SNAPSHOTS;

	static const string CREATE_VOLUME;
	static const string DELETE_VOLUME;
	static const string ATTACH_VOLUME;
	static const string DETACH_VOLUME;
	static const string DESCRIBE_VOLUMES;
	static const string SHOW_DELETE_ON_TERMINATION_FLAG;
	static const string UPDATE_DELETE_ON_TERMINATION_FLAG;

	static const string IMAGE_ID;
	static const string INSTANCE_ID;
	static const string INSTANCE_TYPE_ID;
	static const string VOLUME_ID;
	static const string SNAPSHOT_ID;
	static const string MAX_RESULTS;
	static const string NEXT_TOKEN;
	static const string DETAIL;
	static const string SIZE;
	static const string DEVICE;
	static const string DELETE_ON_TERMINATION;
	static const string KEY_NAME;
	static const string PUBLIC_KEY_MATERIAL;
	static const string DEVICE_NAME;
	static const string VOLUME_SIZE;
	static const string INSTANCE_COUNT;
	static const string SUBNET_ID;
	static const string PRIVATE_IP_ADDRESS;
	static const string SECURITY_GROUP_ID;
	static const string BLOCK;
};
#endif