
#include <cpunit>
#include <model/show_delete_on_termination_flag_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace ShowDeleteOnTerminationResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(ShowDeleteOnTerminationResponseTest, test0) {
    const std::string myxml;
    const model::show_delete_on_termination_flag_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("instance id", resp.get_instance_id(), "");
    assert_equals("volume id", resp.get_volume_id(), "");
    assert_equals("dotflag", resp.get_delete_on_termination(), false);
  }

  CPUNIT_TEST(ShowDeleteOnTerminationResponseTest, test1) {
    const string myxml("<ShowDeleteOnTerminationFlagResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><volume><instanceId>i-8945efce</instanceId><deleteOnTermination>false</deleteOnTermination><volumeId>004ecfe4-4271-47d2-97e9-8400714e7375</volumeId></volume><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId></ShowDeleteOnTerminationFlagResponse>");
    const model::show_delete_on_termination_flag_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("instance id", resp.get_instance_id(), "i-8945efce");
    assert_equals("volume id", resp.get_volume_id(), "004ecfe4-4271-47d2-97e9-8400714e7375");
    assert_equals("dotflag", resp.get_delete_on_termination(), false);
  }

  CPUNIT_TEST(ShowDeleteOnTerminationResponseTest, test2) {
    const string myxml("<ShowDeleteOnTerminationFlagResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><volume><instanceId>i-2476e7c7</instanceId><deleteOnTermination>true</deleteOnTermination><volumeId>34f0b870-c160-4d97-9df6-8456c7569786</volumeId></volume><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId></ShowDeleteOnTerminationFlagResponse>");
    const model::show_delete_on_termination_flag_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    assert_equals("instance id", resp.get_instance_id(), "i-2476e7c7");
    assert_equals("volume id", resp.get_volume_id(), "34f0b870-c160-4d97-9df6-8456c7569786");
    assert_equals("dotflag", resp.get_delete_on_termination(), true);
  }

} 
