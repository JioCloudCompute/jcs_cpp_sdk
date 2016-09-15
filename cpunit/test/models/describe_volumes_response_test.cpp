
#include <cpunit>
#include <model/describe_volumes_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace DescribeVolumesResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(DescribeVolumesResponseTest, test0) {
    const std::string myxml;
    const model::describe_volumes_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const std::vector<model::volume>& volumes = resp.get_volume_set();
    assert_equals("size", volumes.size(), static_cast<size_t>(0));
  }

  CPUNIT_TEST(DescribeVolumesResponseTest, test1) {
    const string myxml("<DescribeVolumes xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><volumeSet><item><status>available</status><encrypted>false</encrypted><volumeId>f67d0d43-e0bf-4055-b3bb-0b152d9681a3</volumeId><attachmentSet><item><device>/dev/vda</device><instanceId>i-98097678</instanceId></item></attachmentSet><snapshotId>90d06065-8dc0-4760-8efb-543fe398fb05</snapshotId><createTime>2016-08-01T15:37:27.000000</createTime><size>20</size></item></volumeSet></DescribeVolumes>");
    const model::describe_volumes_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::volume>& volumes = resp.get_volume_set();
    assert_equals("size", volumes.size(), static_cast<size_t>(1));
    const model::volume& i0 = volumes[0];
    assert_equals("status", i0.get_status(), "available");
    assert_equals("volume id", i0.get_volume_id(), "f67d0d43-e0bf-4055-b3bb-0b152d9681a3");
    assert_equals("device", i0.get_device(), "/dev/vda");
    assert_equals("instance id", i0.get_instance_id(), "i-98097678");
    assert_equals("snapshot id", i0.get_snapshot_id(), "90d06065-8dc0-4760-8efb-543fe398fb05");
    assert_equals("create time", i0.get_create_time(), "2016-08-01T15:37:27.000000");
    assert_equals("size", i0.get_size(), MYUNSIGNED(20));
    assert_equals("encrypted", i0.get_encrypted(), false);
    assert_equals("volume type", i0.get_volumetype(), "");
  }

  CPUNIT_TEST(DescribeVolumesResponseTest, test2) {
    const string myxml("<DescribeVolumes xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><volumeSet><item><status>available</status><encrypted>false</encrypted><volumeId>5081464b-4327-412f-860c-ec71a7d3d1bc</volumeId><attachmentSet></attachmentSet><snapshotId>73e1fa28-12ee-4fdc-957f-67bd377ddc50</snapshotId><createTime>2016-08-21T17:37:27.000000</createTime><size>200</size></item><item><status>in-use</status><encrypted>true</encrypted><volumeId>3e2eda3b-9c84-4cda-8ee7-2fc9b15fb9b2</volumeId><attachmentSet><item><device>/dev/vda</device><instanceId>i-abef789</instanceId></item></attachmentSet><snapshotId>1016bf00-108e-43c3-9299-65627e70678e</snapshotId><createTime>2016-08-22T18:37:27.000000</createTime><size>20</size></item></volumeSet></DescribeVolumes>");
    const model::describe_volumes_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const std::vector<model::volume>& volumes = resp.get_volume_set();
    assert_equals("size", volumes.size(), static_cast<size_t>(2));

    {
    const model::volume& i0 = volumes[0];
    assert_equals("status", i0.get_status(), "available");
    assert_equals("volume id", i0.get_volume_id(), "5081464b-4327-412f-860c-ec71a7d3d1bc");
    assert_equals("device", i0.get_device(), "");
    assert_equals("instance id", i0.get_instance_id(), "");
    assert_equals("snapshot id", i0.get_snapshot_id(), "73e1fa28-12ee-4fdc-957f-67bd377ddc50");
    assert_equals("create time", i0.get_create_time(), "2016-08-21T17:37:27.000000");
    assert_equals("size", i0.get_size(), MYUNSIGNED(200));
    assert_equals("encrypted", i0.get_encrypted(), false);
    assert_equals("volume type", i0.get_volumetype(), "");
    }
    {
    const model::volume& i0 = volumes[1];
    assert_equals("status", i0.get_status(), "in-use");
    assert_equals("volume id", i0.get_volume_id(), "3e2eda3b-9c84-4cda-8ee7-2fc9b15fb9b2");
    assert_equals("device", i0.get_device(), "/dev/vda");
    assert_equals("instance id", i0.get_instance_id(), "i-abef789");
    assert_equals("snapshot id", i0.get_snapshot_id(), "1016bf00-108e-43c3-9299-65627e70678e");
    assert_equals("create time", i0.get_create_time(), "2016-08-22T18:37:27.000000");
    assert_equals("size", i0.get_size(), MYUNSIGNED(20));
    assert_equals("encrypted", i0.get_encrypted(), true);
    assert_equals("volume type", i0.get_volumetype(), "");
    }
  }
 
}
