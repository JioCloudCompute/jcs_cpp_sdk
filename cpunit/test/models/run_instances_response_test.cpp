
#include <cpunit>
#include <model/run_instances_response.hpp>

namespace RunInstanceResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(RunInstanceResponseTest, test0) {
    const string myxml;
    const model::run_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const std::vector<model::instance>& instances = resp.get_instances();
    assert_equals("Instance size", instances.size(), static_cast<size_t>(0));
  }

  CPUNIT_TEST(RunInstanceResponseTest, test1) {
    const string myxml("<RunInstancesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><instancesSet><item><vpcId>vpc-6c362365</vpcId><instanceId>i-8e0b3911</instanceId><imageId>jmi-34e6215c</imageId><privateDnsName>192.168.0.3</privateDnsName><groupSet><item><groupName>g1</groupName><groupId>sg-f13ab921</groupId></item></groupSet><subnetId>subnet-ef345434</subnetId><instanceType>c1.xlarge</instanceType><blockDeviceMapping><item><status>attached</status><deviceName>/dev/vda</deviceName><deleteOnTermination>False</deleteOnTermination><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a47</volumeId><encrypted>True</encrypted></item></blockDeviceMapping><instanceState>running</instanceState><keyName>test</keyName><launchTime>2016-08-22T10:53:51Z</launchTime><privateIpAddress>192.168.0.3</privateIpAddress><ipAddress>10.140.211.97</ipAddress><DnsName>10.140.211.97</DnsName></item></instancesSet><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId></RunInstancesResponse>");
    const model::run_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::instance>& instances = resp.get_instances();
    assert_equals("Instance size", instances.size(), static_cast<size_t>(1));
    {
      const model::instance i0 = instances[0];
      assert_equals("DNS Name", i0.get_dns_name(), "");
      assert_equals("Private DNS Name", i0.get_private_dns_name(), "192.168.0.3");
      assert_equals("Instance id", i0.get_instance_id(), "i-8e0b3911");
      assert_equals("Instance State", i0.get_instance_state(), "running");
      assert_equals("Image id", i0.get_image_id(), "jmi-34e6215c");
      assert_equals("Key name", i0.get_key_name(), "test");
      assert_equals("Launch time", i0.get_launch_time(), "2016-08-22T10:53:51Z");
      assert_equals("Subnet id", i0.get_subnet_id(), "subnet-ef345434");
      assert_equals("VPC id", i0.get_vpc_id(), "vpc-6c362365");
      assert_equals("Instance Type", i0.get_instance_type(), "c1.xlarge");
      assert_equals("Private IP Address", i0.get_private_ip_address(), "192.168.0.3");
      assert_equals("IP Address", i0.get_ip_address(), "10.140.211.97");

      const std::vector<model::block_device_instance>& bdm = i0.get_block_devices();
      const block_device_instance b0 = bdm[0];
      assert_equals("bdm_status", b0.status, "attached");
      assert_equals("device anme", b0.device_name, "/dev/vda");
      assert_equals("deleteOnTermination", static_cast<bool>(b0.delete_on_termination), false);
      assert_equals("volume id", b0.volume_id, "5bf9cfea-0fc1-49e1-9f10-3e8809497a47");
      assert_equals("encrypted", static_cast<bool>(b0.encrypted), true);

      const std::vector<model::group_set>& gs = i0.get_groups();
      model::group_set g0 = gs[0];
      assert_equals("group Name", g0.group_name, "g1");
      assert_equals("group Id", g0.group_id, "sg-f13ab921");
    }
  }

  CPUNIT_TEST(RunInstanceResponseTest, test2) {
    const std::string myxml("<RunInstancesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><instancesSet><item><vpcId>vpc-6c362365</vpcId><instanceId>i-8e0b3911</instanceId><imageId>jmi-34e6215c</imageId><privateDnsName>192.168.0.3</privateDnsName><groupSet><item><groupName>g1</groupName><groupId>sg-f13ab921</groupId></item></groupSet><subnetId>subnet-ef345434</subnetId><instanceType>c1.xlarge</instanceType><blockDeviceMapping><item><status>attached</status><deviceName>/dev/vda</deviceName><deleteOnTermination>False</deleteOnTermination><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a47</volumeId><encrypted>False</encrypted></item></blockDeviceMapping><instanceState>stopped</instanceState><keyName>test</keyName><launchTime>2016-08-22T10:53:51Z</launchTime><privateIpAddress>192.168.0.3</privateIpAddress></item><item><vpcId>vpc-6c362365</vpcId><instanceId>i-8e0b3923</instanceId><imageId>jmi-34e6215c</imageId><privateDnsName>192.168.0.3</privateDnsName><groupSet><item><groupName>g1</groupName><groupId>sg-f13ab921</groupId></item></groupSet><subnetId>subnet-ef345434</subnetId><instanceType>c1.xlarge</instanceType><blockDeviceMapping><item><status>attached</status><deviceName>/dev/vda</deviceName><deleteOnTermination>False</deleteOnTermination><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a47</volumeId><encrypted>False</encrypted></item></blockDeviceMapping><instanceState>running</instanceState><keyName>test</keyName><launchTime>2016-08-22T10:53:51Z</launchTime><privateIpAddress>192.168.0.3</privateIpAddress></item></instancesSet><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId></RunInstancesResponse>");

    const model::run_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const std::vector<model::instance>& instances = resp.get_instances();
    assert_equals("Instance size", instances.size(), static_cast<size_t>(2));
    {
      const model::instance i0 = instances[0];
      assert_equals("DNS Name", i0.get_dns_name(), "");
      assert_equals("Private DNS Name", i0.get_private_dns_name(), "192.168.0.3");
      assert_equals("Instance id", i0.get_instance_id(), "i-8e0b3911");
      assert_equals("Instance State", i0.get_instance_state(), "stopped");
      assert_equals("Image id", i0.get_image_id(), "jmi-34e6215c");
      assert_equals("Key Name", i0.get_key_name(), "test");
      assert_equals("Launch Time", i0.get_launch_time(), "2016-08-22T10:53:51Z");
      assert_equals("Subnet id", i0.get_subnet_id(), "subnet-ef345434");
      assert_equals("VPC id", i0.get_vpc_id(), "vpc-6c362365");
      assert_equals("Instance type", i0.get_instance_type(), "c1.xlarge");
      assert_equals("Private IP Address", i0.get_private_ip_address(), "192.168.0.3");
      assert_equals("IP Address", i0.get_ip_address(), "");

      const std::vector<model::block_device_instance>& bdm = i0.get_block_devices();
      const block_device_instance b0 = bdm[0];
      assert_equals("bdm_status", b0.status, "attached");
      assert_equals("device anme", b0.device_name, "/dev/vda");
      assert_equals("deleteOnTermination", b0.delete_on_termination, false);
      assert_equals("volume id", b0.volume_id, "5bf9cfea-0fc1-49e1-9f10-3e8809497a47");
      assert_equals("encrypted", b0.encrypted, false);

      const std::vector<model::group_set>& gs = i0.get_groups();
      model::group_set g0 = gs[0];
      assert_equals("group Name", g0.group_name, "g1");
      assert_equals("group Id", g0.group_id, "sg-f13ab921");
    }
    {
      const model::instance i0 = instances[1];
      assert_equals("DNS Name", i0.get_dns_name(), "");
      assert_equals("Private DNS Name", i0.get_private_dns_name(), "192.168.0.3");
      assert_equals("Instance id", i0.get_instance_id(), "i-8e0b3923");
      assert_equals("Instance State", i0.get_instance_state(), "running");
      assert_equals("Image id", i0.get_image_id(), "jmi-34e6215c");
      assert_equals("Key Name", i0.get_key_name(), "test");
      assert_equals("Launch Time", i0.get_launch_time(), "2016-08-22T10:53:51Z");
      assert_equals("Subnet id", i0.get_subnet_id(), "subnet-ef345434");
      assert_equals("VPC id", i0.get_vpc_id(), "vpc-6c362365");
      assert_equals("Instance type", i0.get_instance_type(), "c1.xlarge");
      assert_equals("Private IP Address", i0.get_private_ip_address(), "192.168.0.3");
      assert_equals("IP Address", i0.get_ip_address(), "");

      const std::vector<model::block_device_instance>& bdm = i0.get_block_devices();
      const block_device_instance b0 = bdm[0];
      assert_equals("bdm_status", b0.status, "attached");
      assert_equals("device anme", b0.device_name, "/dev/vda");
      assert_equals("deleteOnTermination", b0.delete_on_termination, false);
      assert_equals("volume id", b0.volume_id, "5bf9cfea-0fc1-49e1-9f10-3e8809497a47");
      assert_equals("encrypted", b0.encrypted, false);

      const std::vector<model::group_set>& gs = i0.get_groups();
      model::group_set g0 = gs[0];
      assert_equals("group Name", g0.group_name, "g1");
      assert_equals("group Id", g0.group_id, "sg-f13ab921");
    }

  }
  CPUNIT_TEST(RunInstanceResponseTest, test_simple) {
    std::string myxml("<RunInstancesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\">\n  <requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId>\n  <instancesSet>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>9d516572-70b2-4209-875d-c140f7a3236e</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>5fb5e107-0fc1-49e1-9f10-3e8809497a47</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdo</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>2ffda6de-843e-4e62-b056-c7b2391a3e69</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-8e0b3911</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.3</privateDnsName>\n      <keyName>NMMi_Dev</keyName>\n      <launchTime>2016-08-22T10:53:51Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>sg_NMMi</groupName>\n          <groupId>sg-f13ab921</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.3</privateIpAddress>\n    </item>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>aded140e-6730-4a0f-8536-1aa2009a9f08</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>9d8dd117-7181-4459-ba91-3bb0405891b9</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-ad1fb669</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-3106e30c</imageId>\n      <privateDnsName>192.168.0.52</privateDnsName>\n      <keyName>Dev_Ericsson_RHEL_Srv</keyName>\n      <launchTime>2016-09-08T11:31:13Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>default</groupName>\n          <groupId>sg-e85cddc2</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.52</privateIpAddress>\n    </item>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>a93aa06a-f19d-4f5f-a31e-84263aceec2f</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>cbbe504e-9bc7-4451-8e5d-d7d0c9896309</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-398e36a2</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.47</privateDnsName>\n      <ipAddress>10.141.120.47</ipAddress>\n      <keyName>Dev_Ericsson_RHEL_Srv</keyName>\n      <launchTime>2016-09-08T11:07:57Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>default</groupName>\n          <groupId>sg-e85cddc2</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.47</privateIpAddress>\n    </item>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>39c9f003-e3af-4a7b-8e03-6677c1f096f2</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>185e29b9-2f74-4f30-b33c-57396b2764c3</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-61e3c7e2</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.48</privateDnsName>\n      <ipAddress>10.141.120.48</ipAddress>\n      <keyName>Dev_Ericsson_RHEL_Srv</keyName>\n      <launchTime>2016-09-08T11:08:01Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>default</groupName>\n          <groupId>sg-e85cddc2</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.48</privateIpAddress>\n    </item>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>54e70fc6-ab41-4a0a-bc35-8d071cacf291</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>9d7206dc-210d-4e47-9bf7-aa4dc4da4c8f</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-76bf6100</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.49</privateDnsName>\n      <ipAddress>10.141.120.49</ipAddress>\n      <keyName>Dev_Ericsson_RHEL_Srv</keyName>\n      <launchTime>2016-09-08T11:08:05Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>default</groupName>\n          <groupId>sg-e85cddc2</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.49</privateIpAddress>\n    </item>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>02b49039-d5e0-4fa0-bf4a-1b4bf84c872c</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>9db199ec-452c-49f8-aae8-afb6d2d1fcc1</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-8c247fe8</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.50</privateDnsName>\n      <ipAddress>10.141.120.50</ipAddress>\n      <keyName>Dev_Ericsson_RHEL_Srv</keyName>\n      <launchTime>2016-09-08T11:08:10Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>default</groupName>\n          <groupId>sg-e85cddc2</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.50</privateIpAddress>\n    </item>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>e899befd-bd20-4f96-bc0a-ef70f6e13bba</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>949b215c-fbca-40f7-bc0c-c70c92d5817a</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-4338d98e</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.51</privateDnsName>\n      <ipAddress>10.141.120.51</ipAddress>\n      <keyName>Dev_Ericsson_RHEL_Srv</keyName>\n      <launchTime>2016-09-08T11:08:14Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>default</groupName>\n          <groupId>sg-e85cddc2</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.51</privateIpAddress>\n    </item>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>ed2b01de-190b-4794-bd4f-2f8aa82a57af</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-e6689b08</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.8</privateDnsName>\n      <keyName>SAP_D91</keyName>\n      <launchTime>2016-08-19T09:05:05Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>sg_sap_D91</groupName>\n          <groupId>sg-e2eaaf04</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.2xlarge</instanceType>\n      <privateIpAddress>192.168.0.8</privateIpAddress>\n    </item>\n  </instancesSet>\n</RunInstancesResponse>");

    model::run_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::instance>& instances = resp.get_instances();
    assert_equals("Instance size", instances.size(), static_cast<size_t>(8));

  }

  CPUNIT_TEST(RunInstanceResponseTest, test_simple2) {
    const string myxml("<RunInstancesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\">\n  <requestId>req-722680ecer7a8-43ce-afc1-414720b0aaeb</requestId>\n  <instancesSet>\n    <item>\n      <blockDeviceMapping>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vda</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>9d516572-70b2-4209-875d-c140f7a3236e</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdb</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>5fb5e107-0fc1-49e1-9f10-3e8809497a47</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n        <item>\n          <status>attached</status>\n          <deviceName>/dev/vdo</deviceName>\n          <deleteOnTermination>False</deleteOnTermination>\n          <volumeId>2ffda6de-843e-4e62-b056-c7b2391a3e69</volumeId>\n          <encrypted>False</encrypted>\n        </item>\n      </blockDeviceMapping>\n      <dnsName/>\n      <instanceId>i-8e0b3911</instanceId>\n      <instanceState>running</instanceState>\n      <imageId>jmi-34e6215c</imageId>\n      <privateDnsName>192.168.0.3</privateDnsName>\n      <keyName>NMMi_Dev</keyName>\n      <launchTime>2016-08-22T10:53:51Z</launchTime>\n      <subnetId>subnet-7d4774ba</subnetId>\n      <groupSet>\n        <item>\n          <groupName>sg_NMMi</groupName>\n          <groupId>sg-f13ab921</groupId>\n        </item>\n      </groupSet>\n      <vpcId>vpc-6c362365</vpcId>\n      <instanceType>c1.xlarge</instanceType>\n      <privateIpAddress>192.168.0.3</privateIpAddress>\n    </item>\n  </instancesSet>\n</RunInstancesResponse>");
    model::run_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ecer7a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::instance>& instances = resp.get_instances();
    assert_equals("Instance size", instances.size(), static_cast<size_t>(1));

  }
}
