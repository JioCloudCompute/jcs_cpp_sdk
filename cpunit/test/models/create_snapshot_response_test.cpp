
#include <cpunit>
#include <model/create_snapshot_response.hpp>

namespace CreateSnapshotResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(CreateSnapshotResponseTest, test0) {
    const std::string myxml;
    const model::create_snapshot_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("status", resp.get_status(), "");
    assert_equals("snapshot id", resp.get_snapshot_id(), "");
    assert_equals("volume_id", resp.get_volume_id(), "");
    assert_equals("volume size", resp.get_volume_size(), static_cast<float>(0));
    assert_equals("start time", resp.get_start_time(), "");
    assert_equals("encrypted", resp.get_encrypted(), false);
  }

  CPUNIT_TEST(CreateSnapshotResponseTest, test1) {
    const std::string myxml("<CreateSnapshotResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>pending</status><deleteOnTermination>False</deleteOnTermination><volumeSize>150</volumeSize><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><startTime>2016-08-22T10:53:51Z</startTime><encrypted>False</encrypted><snapshotId>snap-eferf3434</snapshotId><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a47</volumeId></CreateSnapshotResponse>");
    const model::create_snapshot_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("status", resp.get_status(), "pending");
    assert_equals("snapshot id", resp.get_snapshot_id(), "snap-eferf3434");
    assert_equals("volume_id", resp.get_volume_id(), "5bf9cfea-0fc1-49e1-9f10-3e8809497a47");
    assert_equals("volume size", resp.get_volume_size(), static_cast<float>(150));
    assert_equals("start time", resp.get_start_time(), "2016-08-22T10:53:51Z");
    assert_equals("encrypted", resp.get_encrypted(), false);
  }

  CPUNIT_TEST(CreateSnapshotResponseTest, test2) {

    const std::string myxml("<CreateSnapshotResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><status>done</status><deleteOnTermination>False</deleteOnTermination><volumeSize>350</volumeSize><requestId>req-722680ec-57a8-43ce-afc1-414720b0aefc</requestId><startTime>2016-08-23T11:53:51Z</startTime><encrypted>True</encrypted><snapshotId>snap-456790</snapshotId><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497bce</volumeId></CreateSnapshotResponse>");
    const model::create_snapshot_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aefc");
    assert_equals("status", resp.get_status(), "done");
    assert_equals("snapshot id", resp.get_snapshot_id(), "snap-456790");
    assert_equals("volume_id", resp.get_volume_id(), "5bf9cfea-0fc1-49e1-9f10-3e8809497bce");
    assert_equals("volume size", resp.get_volume_size(), static_cast<float>(350));
    assert_equals("start time", resp.get_start_time(), "2016-08-23T11:53:51Z");
    assert_equals("encrypted", resp.get_encrypted(), true);
  }

}
