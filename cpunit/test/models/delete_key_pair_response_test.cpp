
#include <cpunit>
#include <model/delete_key_pair_response.hpp>

namespace DeleteKeyPairResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(DeleteKeyPairResponseTest, test0) {
    const std::string myxml;
    const model::delete_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("result", resp.get_return(), false);
  }

  CPUNIT_TEST(DeleteKeyPairResponseTest, test1) {
    const string myxml("<DeleteKeyPairResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><return>true</return><device>/dev/vdb</device><instanceId>i-ef0b3423</instanceId><encrypted>False</encrypted><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a47</volumeId><deleteOnTermination>False</deleteOnTermination><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId></DeleteKeyPairResponse>");
    const model::delete_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("result", resp.get_return(), true);
  }

  CPUNIT_TEST(DeleteKeyPairResponseTest, test2) {
    const string myxml("<DeleteKeyPairResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><return>False</return><device>/dev/vdc</device><deleteOnTermination>TRUE</deleteOnTermination><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><extra_params>Meant to be ignored</extra_params><instanceId>i-ef455645</instanceId><encrypted>TRUE</encrypted><volumeId>5bf9cfea-0fc1-49e1-9f10-3e8809497a89</volumeId></DeleteKeyPairResponse>");
    const model::delete_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    assert_equals("result", resp.get_return(), false);
  }

}
