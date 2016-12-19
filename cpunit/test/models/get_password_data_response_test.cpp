
#include <cpunit>
#include <model/get_password_data_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace GetPasswordDataResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(GetPasswordDataResponseTest, test0) {
    const std::string myxml;
    const model::get_password_data_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("password data", resp.get_password_data(), "");
    assert_equals("instance id", resp.get_instance_id(), "");
    assert_equals("timestamp", resp.get_timestamp(), "");
  }

  CPUNIT_TEST(GetPasswordDataResponseTest, test1) {
    const string myxml("<GetPasswordData xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><instanceId>i-afcdb23</instanceId><timestamp>2016-04-25T14:28:46.834Z</timestamp><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><passwordData>AbCDFTR7834eRTyUImPl34WdFEsR=</passwordData></GetPasswordData>");
    const model::get_password_data_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("password data", resp.get_password_data(), "AbCDFTR7834eRTyUImPl34WdFEsR=");
    assert_equals("instance id", resp.get_instance_id(), "i-afcdb23");
    assert_equals("timestamp", resp.get_timestamp(), "2016-04-25T14:28:46.834Z");
  }

  CPUNIT_TEST(GetPasswordDataResponseTest, test2) {
    const string myxml("<GetPasswordData xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><instanceId>i-febca23</instanceId><timestamp>2016-03-28T11:08:59.856Z</timestamp><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><passwordData>WTIwWktEWW1pejBrZTR4ERTShbWM=</passwordData></GetPasswordData>");
    const model::get_password_data_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    assert_equals("password data", resp.get_password_data(), "WTIwWktEWW1pejBrZTR4ERTShbWM=");
    assert_equals("instance id", resp.get_instance_id(), "i-febca23");
    assert_equals("timestamp", resp.get_timestamp(), "2016-03-28T11:08:59.856Z");
  }
 
}
