
#include <cpunit>
#include <model/create_volume_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace CreateVolumeResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(CreateVolumeResponseTest, test0) {
    const std::string myxml;
    const model::create_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("status", resp.get_status(), "");
    assert_equals("volume id", resp.get_volume_id(), "");
    assert_equals("snapshot id", resp.get_snapshot_id(), "");
    assert_equals("size", resp.get_size(), MYUNSIGNED(0));
    assert_equals("create time", resp.get_create_time(), "");
    assert_equals("encrypted", resp.get_encrypted(), false);
  }

  CPUNIT_TEST(CreateVolumeResponseTest, test1) {
    const string myxml("<CreateVolumeResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>pending</status><encrypted>False</encrypted><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a47</volumeId><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><snapshotId>snap-eferf3434</snapshotId><createTime>2016-08-22T10:53:51Z</createTime><size>150</size></CreateVolumeResponse>");
    const model::create_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("status", resp.get_status(), "pending");
    assert_equals("volume id", resp.get_volume_id(), "5bf9cfea-0fc1-49e1-9f10-3e8809497a47");
    assert_equals("snapshot id", resp.get_snapshot_id(), "snap-eferf3434");
    assert_equals("size", resp.get_size(), MYUNSIGNED(150));
    assert_equals("create time", resp.get_create_time(), "2016-08-22T10:53:51Z");
    assert_equals("encrypted", resp.get_encrypted(), false); 
  }

  CPUNIT_TEST(CreateVolumeResponseTest, test2) {
    const string myxml("<CreateVolumeResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>active</status><encrypted>True</encrypted><volumeId>5bf9cfea-0fc1-49e1-9f10-3e880ef97a47</volumeId><requestId>req-722680ec-57a8-43ce-afc1-414720b0aefc</requestId><snapshotId></snapshotId><createTime>2016-08-23T12:53:51Z</createTime><size>350</size></CreateVolumeResponse>");
    const model::create_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aefc");
    assert_equals("status", resp.get_status(), "active");
    assert_equals("volume id", resp.get_volume_id(), "5bf9cfea-0fc1-49e1-9f10-3e880ef97a47");
    assert_equals("snapshot id", resp.get_snapshot_id(), "");
    assert_equals("size", resp.get_size(), MYUNSIGNED(350));
    assert_equals("create time", resp.get_create_time(), "2016-08-23T12:53:51Z");
    assert_equals("encrypted", resp.get_encrypted(), true);
  }

  CPUNIT_TEST(CreateVolumeResponseTest, test3) {
    const string myxml("<CreateVolumeResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>active</status><encrypted>True</encrypted><volumeId>5bf9cfea-0fc1-49e1-9f10-3e880ef97a47</volumeId><requestId>req-722680ec-57a8-43ce-afc1-414720b0aefc</requestId><snapshotId/><createTime>2016-08-23T12:53:51Z</createTime><size>350</size></CreateVolumeResponse>");
    const model::create_volume_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aefc");
    assert_equals("status", resp.get_status(), "active");
    assert_equals("volume id", resp.get_volume_id(), "5bf9cfea-0fc1-49e1-9f10-3e880ef97a47");
    assert_equals("snapshot id", resp.get_snapshot_id(), "");
    assert_equals("size", resp.get_size(), MYUNSIGNED(350));
    assert_equals("create time", resp.get_create_time(), "2016-08-23T12:53:51Z");
    assert_equals("encrypted", resp.get_encrypted(), true);
  }


}
