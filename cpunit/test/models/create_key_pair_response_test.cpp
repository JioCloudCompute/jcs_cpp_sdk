
#include <cpunit>
#include <model/create_key_pair_response.hpp>

namespace CreateKeyPairResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(CreateKeyPairResponseTest, test0) {
    const std::string myxml;
    const model::create_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    assert_equals("key_material", resp.get_key_material(), "");
    assert_equals("key_fingerprint", resp.get_key_fingerprint(), "");
    assert_equals("key_name", resp.get_key_name(), "");
  }

  CPUNIT_TEST(CreateKeyPairResponseTest, test1) {
    const std::string myxml("<CreateKeyPairResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><keyMaterial>======BEGIN RSA\nSimpleRSA======END RSA=======</keyMaterial><keyName>compute_test_key</keyName><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><keyFingerprint>0a:8c:85:75:34:3f:3b</keyFingerprint></CreateKeyPairResponse>");
    const model::create_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    assert_equals("key_material", resp.get_key_material(), "======BEGIN RSA\nSimpleRSA======END RSA=======");
    assert_equals("key_fingerprint", resp.get_key_fingerprint(), "0a:8c:85:75:34:3f:3b");
    assert_equals("key_name", resp.get_key_name(), "compute_test_key");
  }

  CPUNIT_TEST(CreateKeyPairResponseTest, test2) {
    const std::string myxml("<CreateKeyPairResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><keyMaterial>======BEGIN RSA\nSimpleRSA======END RSA=======</keyMaterial><keyName>compute_test_key2</keyName><requestId>req-722680ec-57a8-43ce-afc1-414720b0aafc</requestId><extra_params>Meant to be ignored</extra_params><keyFingerprint>0a:8c:85:75:34:dw:3b</keyFingerprint></CreateKeyPairResponse>");
    const model::create_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aafc");
    assert_equals("key_material", resp.get_key_material(), "======BEGIN RSA\nSimpleRSA======END RSA=======");
    assert_equals("key_fingerprint", resp.get_key_fingerprint(), "0a:8c:85:75:34:dw:3b");
    assert_equals("key_name", resp.get_key_name(), "compute_test_key2"); 
  }

}
