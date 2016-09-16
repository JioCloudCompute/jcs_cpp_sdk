
#include <cpunit>
#include <model/detach_volume_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace DetachVolumeResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(DetachVolumeResponseTest, test0) {
    const std::string myxml;
    const model::detach_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("status", resp.get_status(), "");
    assert_equals("device", resp.get_device(), "");
    assert_equals("instance id", resp.get_instance_id(), "");
    assert_equals("volume id", resp.get_volume_id(), "");
    assert_equals("delete on termination", resp.get_delete_on_termination(), false);
  }

  CPUNIT_TEST(DetachVolumeResponseTest, test1) {
    const string myxml("<DetachVolume xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>attaching</status><instanceId>i-978efac</instanceId><volumeId>fb2699a7-e091-4838-a09b-08bd20888e20</volumeId><deleteOnTermination>false</deleteOnTermination><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><device>/dev/vdx</device></DetachVolume>");
    const model::detach_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("status", resp.get_status(), "attaching");
    assert_equals("device", resp.get_device(), "/dev/vdx");
    assert_equals("instance id", resp.get_instance_id(), "i-978efac");
    assert_equals("volume id", resp.get_volume_id(), "fb2699a7-e091-4838-a09b-08bd20888e20");
    assert_equals("delete on termination", resp.get_delete_on_termination(), false);

  }

  CPUNIT_TEST(DetachVolumeResponseTest, test2) {
    const string myxml("<DetachVolume xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>detaching</status><instanceId>i-09efbcad</instanceId><volumeId>b38870f2-21c5-4df3-ac56-0fb6675cc1dd</volumeId><deleteOnTermination>true</deleteOnTermination><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><device>/dev/vdk</device></DetachVolume>");
    const model::detach_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    assert_equals("status", resp.get_status(), "detaching");
    assert_equals("device", resp.get_device(), "/dev/vdk");
    assert_equals("instance id", resp.get_instance_id(), "i-09efbcad");
    assert_equals("volume id", resp.get_volume_id(), "b38870f2-21c5-4df3-ac56-0fb6675cc1dd");
    assert_equals("delete on termination", resp.get_delete_on_termination(), true);

  }
 
}
