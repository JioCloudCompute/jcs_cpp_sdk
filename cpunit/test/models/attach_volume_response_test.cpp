
#include <cpunit>
#include <model/attach_volume_response.hpp>

namespace AttachVolumeResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(AttachVolumeResponseTest, test0) {
    const std::string myxml;
    const model::attach_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("status", resp.get_status(), "");
    assert_equals("device", resp.get_device(), "");
    assert_equals("instance_id", resp.get_instance_id(), "");
    assert_equals("volume id", resp.get_volume_id(), "");
    assert_equals("delete on termination", resp.get_delete_on_termination(), false);
  }

  CPUNIT_TEST(AttachVolumeResponseTest, test1) {
    const string myxml("<AttachVolumeResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>attaching</status><device>/dev/vdb</device><instanceId>i-ef0b3423</instanceId><encrypted>False</encrypted><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a47</volumeId><deleteOnTermination>False</deleteOnTermination><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId></AttachVolumeResponse>");
    const model::attach_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("status", resp.get_status(), "attaching");
    assert_equals("device", resp.get_device(), "/dev/vdb");
    assert_equals("instance_id", resp.get_instance_id(), "i-ef0b3423");
    assert_equals("volume id", resp.get_volume_id(), "5bf9cfea-0fc1-49e1-9f10-3e8809497a47");
    assert_equals("delete on termination", resp.get_delete_on_termination(), false);

    
  }

  CPUNIT_TEST(AttachVolumeResponseTest, test2) {
    const string myxml("<AttachVolumeResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>detaching</status><device>/dev/vdc</device><deleteOnTermination>TRUE</deleteOnTermination><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><extra_params>Meant to be ignored</extra_params><instanceId>i-ef455645</instanceId><encrypted>TRUE</encrypted><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a89</volumeId></AttachVolumeResponse>");
    const model::attach_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    assert_equals("status", resp.get_status(), "detaching");
    assert_equals("device", resp.get_device(), "/dev/vdc");
    assert_equals("instance_id", resp.get_instance_id(), "i-ef455645");
    assert_equals("volume id", resp.get_volume_id(), "5bf9cfea-0fc1-49e1-9f10-3e8809497a89");
    assert_equals("delete on termination", resp.get_delete_on_termination(), true);

  }

}
