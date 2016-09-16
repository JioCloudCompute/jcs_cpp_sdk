
#include <cpunit>
#include <model/start_instances_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace StartInstancesResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(StartInstancesResponseTest, test0) {
    const std::string myxml;
    const model::start_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const vector<model::instance_state_set>& iss = resp.get_instances();
    assert_equals("size", iss.size(), static_cast<size_t>(0));
  }

  CPUNIT_TEST(StartInstancesResponseTest, test1) {
    const string myxml("<StartInstancesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><instancesSet><item><instanceId>i-8945efab</instanceId><currentState>running</currentState><previousState>shutting-down</previousState></item></instancesSet><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId></StartInstancesResponse>");
    const model::start_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const vector<model::instance_state_set>& iss = resp.get_instances();
    assert_equals("size", iss.size(), static_cast<size_t>(1));
    {
      const model::instance_state_set& is0 = iss[0];
      assert_equals("instance id", is0.get_instance_id(), "i-8945efab");
      assert_equals("current state", is0.get_current_state(), "running");
      assert_equals("previous state", is0.get_previous_state(), "shutting-down");
    }
  }

  CPUNIT_TEST(StartInstancesResponseTest, test2) {
    const string myxml("<StartInstancesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><instancesSet><item><instanceId>i-9345ebac</instanceId><currentState>pending</currentState><previousState>terminated</previousState></item><item><instanceId>i-45bcadef</instanceId><currentState>stopped</currentState><previousState>stopping</previousState></item></instancesSet><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId></StartInstancesResponse>");
    const model::start_instances_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const vector<model::instance_state_set>& iss = resp.get_instances();
    assert_equals("size", iss.size(), static_cast<size_t>(2));
    {
      const model::instance_state_set& is0 = iss[0];
      assert_equals("instance id", is0.get_instance_id(), "i-9345ebac");
      assert_equals("current state", is0.get_current_state(), "pending");
      assert_equals("previous state", is0.get_previous_state(), "terminated");
    }
    {
      const model::instance_state_set& is0 = iss[1];
      assert_equals("instance id", is0.get_instance_id(), "i-45bcadef");
      assert_equals("current state", is0.get_current_state(), "stopped");
      assert_equals("previous state", is0.get_previous_state(), "stopping");
    }


  }
 
}
