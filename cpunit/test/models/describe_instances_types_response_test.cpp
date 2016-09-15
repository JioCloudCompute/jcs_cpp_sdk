
#include <cpunit>
#include <model/describe_instance_types_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace DescribeInstanceTypesResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(DescribeInstanceTypesResponseTest, test0) {
    const std::string myxml;
    const model::describe_instance_types_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const std::vector<model::instance_type>& instancetypes = resp.get_instance_types();
    assert_equals("size", instancetypes.size(), static_cast<size_t>(0));
  }

  CPUNIT_TEST(DescribeInstanceTypesResponseTest, test1) {
    const string myxml("<DescribeInstanceTypes xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><instanceTypes><item><vcpus>1</vcpus><ram>3.75</ram><id>c1.small</id></item></instanceTypes></DescribeInstanceTypes>");
    const model::describe_instance_types_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::instance_type>& instancetypes = resp.get_instance_types();
    assert_equals("size", instancetypes.size(), static_cast<size_t>(1));
    const model::instance_type& i0 = instancetypes[0];
    assert_equals("image id", i0.get_vcpus(), MYUNSIGNED(1));
    assert_equals("is public", i0.get_ram(), 3.75f);
    assert_equals("name", i0.get_id(), "c1.small");
  }

  CPUNIT_TEST(DescribeInstanceTypesResponseTest, test2) {
    const string myxml("<DescribeInstanceTypes xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><instanceTypes><item><vcpus>2</vcpus><ram>8</ram><id>c1.medium</id></item><item><vcpus>4</vcpus><ram>16</ram><id>c1.large</id></item></instanceTypes></DescribeInstanceTypes>");
    const model::describe_instance_types_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const std::vector<model::instance_type>& instancetypes = resp.get_instance_types();
    assert_equals("size", instancetypes.size(), static_cast<size_t>(2));

    {
    const model::instance_type& i0 = instancetypes[0];
    assert_equals("image id", i0.get_vcpus(), MYUNSIGNED(2));
    assert_equals("is public", i0.get_ram(), 8.0f);
    assert_equals("name", i0.get_id(), "c1.medium");
    }
    {
    const model::instance_type& i0 = instancetypes[1];
    assert_equals("image id", i0.get_vcpus(), MYUNSIGNED(4));
    assert_equals("is public", i0.get_ram(), 16.0f);
    assert_equals("name", i0.get_id(), "c1.large");
    }
  }
 
}
