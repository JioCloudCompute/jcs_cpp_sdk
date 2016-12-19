#!/bin/python

xml_ns = 'https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/'

#level_enabled = False
#evel_enabled = True

def get_value(key, values):
    mystr = '<%s>'%(key,)
    if type(values) is list:
        for elem in values:
            mystr += '<item>'
            if type(elem) is dict:
                mystr += dict_value(elem)
            elif type(elem) is not list:
                mystr += elem
            mystr += '</item>'
    elif type(values) is dict:
        mystr += dict_value(values)
    elif type(values) is str:
        mystr += values
    else:
        mystr += `values`
    mystr += '</%s>'%(key,)
    return mystr

def dict_value(mydict):
    xml_str = ''
    for k,v in mydict.items():
        xml_str += get_value(k, v)
    return xml_str

'''def make_tc_xml(category, top_name, test_case):
    #xml_str = '<%s xmlns=\\"%s\\">'%(top_name, xml_ns)
    for elem in test_case:
        xml_str = '<%s xmlns="%s">'%(top_name, xml_ns)
        xml_str += dict_value(elem)
        xml_str += '</%s>\n'%(top_name,)
        print xml_str
    return xml_str
'''

def make_tc_xml(category, top_name, test_case):
    #xml_str = '<%s xmlns="%s">'%(top_name, xml_ns)
    #for elem in test_case:
    xml_str = '<%s xmlns=\\"%s\\">'%(top_name, xml_ns)
    xml_str += dict_value(test_case)
    xml_str += '</%s>\n'%(top_name,)
    print xml_str
    #return xml_str

def make_tc_suites(test_suites):
    for t in test_suites:
        #print `t`
        #print `t['test_cases']`
        for tc in t['test_cases']:
            make_tc_xml(t['category'], t['top_name'], tc)
            #print "XML: "
            #print xml


test_suites = [

        {
        'category':'describe_instance', 
        'top_name':'DescribeInstancesResponse',
        'test_cases': [
            {
                'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
                'instancesSet': [
                    {
                        'blockDeviceMapping': [
                            {
                                'status':'attached', 
                                'deviceName':'/dev/vda', 
                                'deleteOnTermination':'False', 
                                'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497a47', 
                                'encrypted':'True', 
                                'deleteOnTermination':'False'
                            }
                        ],
                        'instanceId':'i-8e0b3911',
                        'instanceState':'running',
                        'imageId':'jmi-34e6215c',
                        'privateDnsName': '192.168.0.3',
                        'DnsName': '10.140.211.97',
                        'keyName':'test',
                        'groupSet':[
                                        {
                                            'groupName':'g1',
                                            'groupId':'sg-f13ab921'
                                        }
                                    ],
                        'vpcId': 'vpc-6c362365',
                        'subnetId': 'subnet-ef345434',
                        'instanceType':'c1.xlarge',
                        'privateIpAddress': '192.168.0.3',
                        'launchTime': '2016-08-22T10:53:51Z',
                        'ipAddress': '10.140.211.97'
                    },
                ]
            },
            {
                'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
                'instancesSet': [
                    {
                        'blockDeviceMapping': [
                            {
                                'status':'attached', 
                                'deviceName':'/dev/vda', 
                                'deleteOnTermination':'False', 
                                'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497a47', 
                                'encrypted':'False', 
                                'deleteOnTermination':'False'
                            }
                        ],
                        'instanceId':'i-8e0b3911',
                        'instanceState':'stopped',
                        'imageId':'jmi-34e6215c',
                        'privateDnsName': '192.168.0.3',
                        'keyName':'test',
                        'groupSet':[
                                        {
                                            'groupName':'g1',
                                            'groupId':'sg-f13ab921'
                                        }
                                    ],
                        'vpcId': 'vpc-6c362365',
                        'instanceType':'c1.xlarge',
                        'launchTime': '2016-08-22T10:53:51Z',
                        'subnetId': 'subnet-ef345434',
                        'privateIpAddress': '192.168.0.3'
                    },
                    {
                        'blockDeviceMapping': [
                            {
                                'status':'attached', 
                                'deviceName':'/dev/vda', 
                                'deleteOnTermination':'False', 
                                'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497a47', 
                                'encrypted':'False', 
                                'deleteOnTermination':'False'
                            }
                        ],
                        'instanceId':'i-8e0b3923',
                        'instanceState':'running',
                        'imageId':'jmi-34e6215c',
                        'privateDnsName': '192.168.0.3',
                        'keyName':'test',
                        'groupSet':[
                                        {
                                            'groupName':'g1',
                                            'groupId':'sg-f13ab921'
                                        }
                                    ],
                        'vpcId': 'vpc-6c362365',
                        'instanceType':'c1.xlarge',
                        'launchTime': '2016-08-22T10:53:51Z',
                        'subnetId': 'subnet-ef345434',
                        'privateIpAddress': '192.168.0.3'
                    },

                ]
            }
            
        ]
    },
    {
    'category':'attach_volume', 
    'top_name':'AttachVolumeResponse',
    'test_cases': [
        {
            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
            'status':'attaching', 
            'device':'/dev/vdb', 
            'deleteOnTermination':'False', 
            'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497a47', 
            'encrypted':'False',
            'instanceId': 'i-ef0b3423'
        },
        {
            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
            'status':'detaching', 
            'device':'/dev/vdc', 
            'deleteOnTermination':'TRUE', 
            'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497a89', 
            'encrypted':'TRUE',
            'instanceId': 'i-ef455645',
            'extra_params':'Meant to be ignored'
        }
        
    ]
    },
    {
    'category':'create_key_pair', 
    'top_name':'CreateKeyPairResponse',
    'test_cases': [
        {
            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
            'keyMaterial': '======BEGIN RSA\\nSimpleRSA======END RSA=======',
            'keyName': 'compute_test_key',
            'keyFingerprint': '0a:8c:85:75:34:3f:3b',
        },
        {
            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
            'keyMaterial': '======BEGIN RSA\\nSimpleRSA======END RSA=======',
            'keyName': 'compute_test_key2',
            'keyFingerprint': '0a:8c:85:75:34:3f:3b',
            'extra_params':'Meant to be ignored'
        }
        
    ]
    },
    {
    'category':'create_snapshot', 
    'top_name':'CreateSnapshotResponse',
    'test_cases': [
        {
            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
            'status':'pending',
            'snapshotId':'snap-eferf3434',
            'volumeSize': 150,
            'deleteOnTermination':'False',
            'startTime': '2016-08-22T10:53:51Z',
            'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497a47', 
            'encrypted':'False',
        },
        {

            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aefc',
            'status':'done',
            'snapshotId':'snap-456790',
            'volumeSize': 350,
            'deleteOnTermination':'False',
            'startTime': '2016-08-23T11:53:51Z',
            'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497bce',
            'encrypted':'True',
        }
    ]
    },
    {
    'category':'create_volume', 
    'top_name':'CreateVolumeResponse',
    'test_cases': [
        {
            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
            'status':'pending',
            'snapshotId':'snap-eferf3434',
            'size': 150,
            'createTime': '2016-08-22T10:53:51Z',
            'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e8809497a47', 
            'encrypted':'False',
        },
        {

            'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aefc',
            'status':'pending',
            'snapshotId':'',
            'size': 150,
            'createTime': '2016-08-23T12:53:51Z',
            'volumeId':'5bf9cfea-0fc1-49e1-9f10-3e880ef97a47', 
            'encrypted':'True',
        }
    ]
    },

    {
   'category':'describe_images', 
   'top_name':'DescribeImagesResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
           'imagesSet': [
               {
                   'blockDeviceMapping': [
                       {
                           'deviceName':'/dev/vda', 
                           'deleteOnTermination':'False', 
                           'volumeSize':8, 
                           'encrypted':'True', 
                           'snapshotId': 'snap-0001'
                       }
                   ],
                   'imageId':'jmi-784567',
                   'isPublic':'true',
                   'name':'Ubuntu 1.0',
                   'imageState': 'available',
                   'architecture': 'x86_64',
                   'imageType':'machine',
               },
           ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'imagesSet': [
               {
                   'blockDeviceMapping': [
                       {
                           'deviceName':'/dev/vda', 
                           'deleteOnTermination':'False', 
                           'volumeSize':20, 
                           'encrypted':'True', 
                           'snapshotId': 'snap-0023'
                       }
                   ],
                   'imageId':'jmi-784989',
                   'isPublic':'true',
                   'name':'Ubuntu-14.0',
                   'imageState': 'available',
                   'architecture': 'x86_64',
                   'imageType':'machine',
               },
               {
                   'blockDeviceMapping': [
                       {
                           'deviceName':'/dev/vda',
                           'deleteOnTermination':'False',
                           'volumeSize':8,
                           'encrypted':'True',
                           'snapshotId': 'snap-0001'
                       }
                   ],
                   'imageId':'jmi-9eafbcd',
                   'isPublic':'false',
                   'name':'Ubuntu-16.0',
                   'imageState': 'available',
                   'architecture': 'x86_64',
                   'imageType':'machine',
               },
           ]
       }
       
   ]
   },
    {
   'category':'describe_instance_types', 
   'top_name':'DescribeInstanceTypesResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',

           'instanceTypes': [
               {
                   'vcpus':'1',
                   'ram':'3.75',
                   'id':'c1.small',
               },
           ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'instanceTypes': [
               {
                   'vcpus':'2',
                   'ram':'8',
                   'id':'c1.medium',
               },
               {
                   'vcpus':'4',
                   'ram':'16',
                   'id':'c1.large',
               },
           ]
       }
       
   ]
   },
  {
   'category':'describe_key_pairs',
   'top_name':'DescribeKeyPairsResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',

           'keySet': [
               {
                   'keyName':'key-1',
                   'keyFingerprint':'80:45:ef:bd:ca:cf:bf',
               },
           ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'keySet': [
               {
                   'keyName':'key-2',
                   'keyFingerprint':'80:45:ef:bd:ba:cf:bf',
               },
               {
                   'keyName':'key-3',
                   'keyFingerprint':'80:45:df:cd:ca:cf:bf',
               },
           ]
       }
       
   ]
   },
  {
   'category':'describe_snapshots',
   'top_name':'DescribeSnapshotsResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',

           'snapshotSet': [
               {
                   'status':'done',
                   'snapshotId':'aefdcba34-3456-789a-bcde-f01234',
                   'volumeSize': '100',
                   'volumeId': 'febac234-4589-0897-b2ab-f0acdbe',
                   'startTime': '2016-08-23T12:53:51Z',
                   'encrypted':'true'
               },
           ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',

           'snapshotSet': [
               {
                   'status':'done',
                   'snapshotId':'aefdcba34-3456-889a-bcde-eb09ecd',
                   'volumeId': 'febac234-4589-0897-b2ab-98763bd',
               },
           ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'snapshotSet': [
               {
                   'status':'pending',
                   'snapshotId':'aefdcba34-3456-789a-bcde-fbec34',
                   'volumeSize': '100',
                   'volumeId': 'febac234-4589-0ab7-b2ab-eb09ecd',
                   'startTime': '2016-08-23T14:53:51Z',
                   'encrypted':'false'
               },
               {
                   'status':'done',
                   'snapshotId':'fea3abcde-3456-789a-bcde-f01234',
                   'volumeSize': '200',
                   'volumeId': 'febac234-4589-0897-b2ab-f0acdbe',
                   'startTime': '2016-08-23T12:53:51Z',
                   'encrypted':'true'
               },
           ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'snapshotSet': [
               {
                   'status':'done',
                   'snapshotId':'aefdcba34-3456-789a-bcde-f01234',
                   'volumeId': 'febac234-4589-0897-b2ab-f0acdbe',
               },
               {
                   'status':'done',
                   'snapshotId':'aefdcba34-3456-789a-bcde-f01234',
                   'volumeId': 'febac234-4589-0897-b2ab-f0acdbe',
               },
           ]
       }
       
   ]
   },
  {
   'category':'describe_volumes',
   'top_name':'DescribeVolumesResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',

           'volumeSet': [
               {
                   'status':'available',
                   'volumeId': 'f67d0d43-e0bf-4055-b3bb-0b152d9681a3',
                   'attachmentSet':[{'device':'/dev/vda', 'instanceId':'i-98097678'}],
                   'snapshotId':'90d06065-8dc0-4760-8efb-543fe398fb05',
                   'createTime':'2016-08-01T15:37:27.000000',
                   'size': '20',
                   'encrypted': 'false',
               },
           ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'volumeSet': [
               {
                   'status':'available',
                   'volumeId': '5081464b-4327-412f-860c-ec71a7d3d1bc',
                   'attachmentSet':[],
                   'snapshotId':'73e1fa28-12ee-4fdc-957f-67bd377ddc50',
                   'createTime':'2016-08-21T17:37:27.000000',
                   'size': '200',
                   'encrypted': 'false',
               },
               {
                   'status':'in-use',
                   'volumeId': '3e2eda3b-9c84-4cda-8ee7-2fc9b15fb9b2',
                   'attachmentSet':[{'device':'/dev/vda', 'instanceId':'i-abef789'}],
                   'snapshotId':'1016bf00-108e-43c3-9299-65627e70678e',
                   'createTime':'2016-08-22T18:37:27.000000',
                   'size': '20',
                   'encrypted': 'true',
               },

           ]
       }
       
   ]
   },
  {
   'category':'detach_volume',
   'top_name':'DetachVolumeResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
           'deleteOnTermination': 'false',
           'device': '/dev/vdx',
           'instanceId': 'i-978efac',
           'status': 'attaching',
           'volumeId':'fb2699a7-e091-4838-a09b-08bd20888e20',
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'deleteOnTermination': 'true',
           'device': '/dev/vdk',
           'instanceId': 'i-09efbcad',
           'status': 'detaching',
           'volumeId':'b38870f2-21c5-4df3-ac56-0fb6675cc1dd',
       }
       
   ]
   },
  {
   'category':'import_key_pair',
   'top_name':'ImportKeyPairResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
           'keyName': 'key-123',
           'keyFingerprint': '1f:ef:bd:cd:b5:67:84:52:15'
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'keyName': '123-key',
           'keyFingerprint': '13:df:bd:cd:b5:67:84:52:14'
       }
       
   ]
   },
  {
   'category':'reboot_instances',
   'top_name':'RebootInstancesResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
           'instancesSet': [
                {
                    'instanceId':'i-8945efab',
                    'currentState':'running',
                    'previousState':'shutting-down',
                }
            ]
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'instancesSet': [
                {
                    'instanceId':'i-9345ebac',
                    'currentState':'pending',
                    'previousState':'terminated',

                },
                {
                    'instanceId':'i-45bcadef',
                    'currentState':'stopped',
                    'previousState':'stopping',
                }
            ]
       }
       
   ]
   },
  {
   'category':'show_delete_on_termination_flag',
   'top_name':'ShowDeleteOnTerminationFlagResponse',
   'test_cases': [
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaeb',
           'volume':{
            'deleteOnTermination': 'false',
            'volumeId': '004ecfe4-4271-47d2-97e9-8400714e7375',
            'instanceId':'i-8945efce'}
       },
       {
           'requestId':'req-722680ec-57a8-43ce-afc1-414720b0aaec',
           'volume':{
            'deleteOnTermination': 'true',
            'volumeId': '34f0b870-c160-4d97-9df6-8456c7569786',
            'instanceId':'i-2476e7c7',
            }
       }
   ]
   },
]

make_tc_suites(test_suites)
