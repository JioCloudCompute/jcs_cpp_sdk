
#include <cpunit>
#include <model/describe_snapshots_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace DescribeSnapshotsResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(DescribeSnapshotsResponseTest, test0) {
    const std::string myxml;
    const model::describe_snapshots_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const std::vector<model::snapshot>& snapshots = resp.get_snapshot_set();
    assert_equals("size", snapshots.size(), static_cast<size_t>(0));
  }

  CPUNIT_TEST(DescribeSnapshotsResponseTest, test1) {
    const string myxml("<DescribeSnapshots xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><snapshotSet><item><status>done</status><encrypted>true</encrypted><volumeId>febac234-4589-0897-b2ab-f0acdbe</volumeId><volumeSize>100</volumeSize><startTime>2016-08-23T12:53:51Z</startTime><snapshotId>aefdcba34-3456-789a-bcde-f01234</snapshotId></item></snapshotSet></DescribeSnapshots>");
    const model::describe_snapshots_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::snapshot>& snapshots = resp.get_snapshot_set();
    assert_equals("size", snapshots.size(), static_cast<size_t>(1));
    const model::snapshot& i0 = snapshots[0];
    assert_equals("snapshot id", i0.get_snapshot_id(), "aefdcba34-3456-789a-bcde-f01234");
    assert_equals("volume id", i0.get_volume_id(), "febac234-4589-0897-b2ab-f0acdbe");
    assert_equals("volume size", i0.get_volume_size(), MYUNSIGNED(100));
    assert_equals("status", i0.get_status(), "done");
    assert_equals("start time", i0.get_start_time(), "2016-08-23T12:53:51Z");
    assert_equals("encrypted", i0.get_encrypted(), true);
  }

  CPUNIT_TEST(DescribeSnapshotsResponseTest, test11) {
    const string myxml("<DescribeSnapshots xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><snapshotSet><item><status>done</status><snapshotId>aefdcba34-3456-889a-bcde-eb09ecd</snapshotId><volumeId>febac234-4589-0897-b2ab-98763bd</volumeId></item></snapshotSet></DescribeSnapshots>");
    const model::describe_snapshots_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::snapshot>& snapshots = resp.get_snapshot_set();
    assert_equals("size", snapshots.size(), static_cast<size_t>(1));
    const model::snapshot& i0 = snapshots[0];
    assert_equals("snapshot id", i0.get_snapshot_id(), "aefdcba34-3456-889a-bcde-eb09ecd");
    assert_equals("volume id", i0.get_volume_id(), "febac234-4589-0897-b2ab-98763bd");
    assert_equals("volume size", i0.get_volume_size(), MYUNSIGNED(0));
    assert_equals("status", i0.get_status(), "done");
    assert_equals("start time", i0.get_start_time(), "");
    assert_equals("encrypted", i0.get_encrypted(), false);
  }

  CPUNIT_TEST(DescribeSnapshotsResponseTest, test2) {
    const string myxml("<DescribeSnapshots xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><snapshotSet><item><status>pending</status><encrypted>false</encrypted><volumeId>febac234-4589-0ab7-b2ab-eb09ecd</volumeId><volumeSize>100</volumeSize><startTime>2016-08-23T14:53:51Z</startTime><snapshotId>aefdcba34-3456-789a-bcde-fbec34</snapshotId></item><item><status>done</status><encrypted>true</encrypted><volumeId>febac234-4589-0897-b2ab-f0acdbe</volumeId><volumeSize>200</volumeSize><startTime>2016-08-23T12:53:51Z</startTime><snapshotId>fea3abcde-3456-789a-bcde-f01234</snapshotId></item></snapshotSet></DescribeSnapshots>");
    const model::describe_snapshots_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const std::vector<model::snapshot>& snapshots = resp.get_snapshot_set();
    assert_equals("size", snapshots.size(), static_cast<size_t>(2));
    {
    const model::snapshot& i0 = snapshots[0];
    assert_equals("snapshot id", i0.get_snapshot_id(), "aefdcba34-3456-789a-bcde-fbec34");
    assert_equals("volume id", i0.get_volume_id(), "febac234-4589-0ab7-b2ab-eb09ecd");
    assert_equals("volume size", i0.get_volume_size(), MYUNSIGNED(100));
    assert_equals("status", i0.get_status(), "pending");
    assert_equals("start time", i0.get_start_time(), "2016-08-23T14:53:51Z");
    assert_equals("encrypted", i0.get_encrypted(), false);
    }
    {
    const model::snapshot& i0 = snapshots[1];
    assert_equals("snapshot id", i0.get_snapshot_id(), "fea3abcde-3456-789a-bcde-f01234");
    assert_equals("volume id", i0.get_volume_id(), "febac234-4589-0897-b2ab-f0acdbe");
    assert_equals("volume size", i0.get_volume_size(), MYUNSIGNED(200));
    assert_equals("status", i0.get_status(), "done");
    assert_equals("start time", i0.get_start_time(), "2016-08-23T12:53:51Z");
    assert_equals("encrypted", i0.get_encrypted(), true);
    }
  }
  CPUNIT_TEST(DescribeSnapshotsResponseTest, test21) {
    const string myxml("<DescribeSnapshots xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><snapshotSet><item><status>pending</status><snapshotId>aefdcba34-3456-789a-bcde-f01234</snapshotId><volumeId>febac234-4589-0897-b2ab-f0acdbe</volumeId></item><item><status>done</status><snapshotId>aefdcba34-3456-789a-bcde-f01234</snapshotId><volumeId>febac234-4589-0897-b2ab-f0acdbe</volumeId></item></snapshotSet></DescribeSnapshots>");
    const model::describe_snapshots_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const std::vector<model::snapshot>& snapshots = resp.get_snapshot_set();
    assert_equals("size", snapshots.size(), static_cast<size_t>(2));
    {
    const model::snapshot& i0 = snapshots[0];
    assert_equals("snapshot id", i0.get_snapshot_id(), "aefdcba34-3456-789a-bcde-f01234");
    assert_equals("volume id", i0.get_volume_id(), "febac234-4589-0897-b2ab-f0acdbe");
    assert_equals("volume size", i0.get_volume_size(), MYUNSIGNED(0));
    assert_equals("status", i0.get_status(), "pending");
    assert_equals("start time", i0.get_start_time(), "");
    assert_equals("encrypted", i0.get_encrypted(), false);
    }
    {
    const model::snapshot& i0 = snapshots[1];
    assert_equals("snapshot id", i0.get_snapshot_id(), "aefdcba34-3456-789a-bcde-f01234");
    assert_equals("volume id", i0.get_volume_id(), "febac234-4589-0897-b2ab-f0acdbe");
    assert_equals("volume size", i0.get_volume_size(), MYUNSIGNED(0));
    assert_equals("status", i0.get_status(), "done");
    assert_equals("start time", i0.get_start_time(), "");
    assert_equals("encrypted", i0.get_encrypted(), false);
    }

  }

}
