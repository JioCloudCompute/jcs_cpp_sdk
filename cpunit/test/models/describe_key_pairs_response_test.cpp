
#include <cpunit>
#include <model/describe_key_pairs_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace DescribeKeyPairsResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(DescribeKeyPairsResponseTest, test0) {
    const std::string myxml;
    const model::describe_key_pairs_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const std::vector<model::key_pair>& keypairs = resp.get_key_pairs();
    assert_equals("size", keypairs.size(), static_cast<size_t>(0));
  }

  CPUNIT_TEST(DescribeKeyPairsResponseTest, test1) {
    const string myxml("<DescribeKeyPairs xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><keySet><item><keyName>key-1</keyName><keyFingerprint>80:45:ef:bd:ca:cf:bf</keyFingerprint></item></keySet><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId></DescribeKeyPairs>");
    const model::describe_key_pairs_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::key_pair>& keypairs = resp.get_key_pairs();
    assert_equals("size", keypairs.size(), static_cast<size_t>(1));
    const model::key_pair& i0 = keypairs[0];
    assert_equals("key name", i0.get_key_name(), "key-1");
    assert_equals("key fingerprint", i0.get_key_fingerprint(), "80:45:ef:bd:ca:cf:bf");
  }

  CPUNIT_TEST(DescribeKeyPairsResponseTest, test2) {
    const string myxml("<DescribeKeyPairs xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><keySet><item><keyName>key-2</keyName><keyFingerprint>80:45:ef:bd:ba:cf:bf</keyFingerprint></item><item><keyName>key-3</keyName><keyFingerprint>80:45:df:cd:ca:cf:bf</keyFingerprint></item></keySet><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId></DescribeKeyPairs>");
    const model::describe_key_pairs_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const std::vector<model::key_pair>& keypairs = resp.get_key_pairs();
    assert_equals("size", keypairs.size(), static_cast<size_t>(2));

    {
    const model::key_pair& i0 = keypairs[0];
    assert_equals("key name", i0.get_key_name(), "key-2");
    assert_equals("key fingerprint", i0.get_key_fingerprint(), "80:45:ef:bd:ba:cf:bf");
    }
    {
    const model::key_pair& i0 = keypairs[1];
    assert_equals("key name", i0.get_key_name(), "key-3");
    assert_equals("key fingerprint", i0.get_key_fingerprint(), "80:45:df:cd:ca:cf:bf");
    }
  }
 
}
