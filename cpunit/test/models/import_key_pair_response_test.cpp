
#include <cpunit>
#include <model/import_key_pair_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace ImportKeyPairResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(ImportKeyPairResponseTest, test0) {
    const std::string myxml;
    const model::import_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const model::key_pair& keypair = resp.get_key();
    assert_equals("key name", keypair.get_key_name(), "");
    assert_equals("key fingerprint", keypair.get_key_fingerprint(), "");
    assert_equals("key material", keypair.get_key_material(), "");
  }

  CPUNIT_TEST(ImportKeyPairResponseTest, test1) {
    const string myxml("<ImportKeyPairResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><keyName>key-123</keyName><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><keyFingerprint>1f:ef:bd:cd:b5:67:84:52:15</keyFingerprint></ImportKeyPairResponse>");
    const model::import_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const model::key_pair& keypair = resp.get_key();
    assert_equals("key name", keypair.get_key_name(), "key-123");
    assert_equals("key fingerprint", keypair.get_key_fingerprint(), "1f:ef:bd:cd:b5:67:84:52:15");
    assert_equals("key material", keypair.get_key_material(), "");
  }

  CPUNIT_TEST(ImportKeyPairResponseTest, test2) {
    const string myxml("<ImportKeyPairResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><keyName>123-key</keyName><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><keyFingerprint>13:df:bd:cd:b5:67:84:52:14</keyFingerprint></ImportKeyPairResponse>");
    const model::import_key_pair_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const model::key_pair& keypair = resp.get_key();
    assert_equals("key name", keypair.get_key_name(), "123-key");
    assert_equals("key fingerprint", keypair.get_key_fingerprint(), "13:df:bd:cd:b5:67:84:52:14");
    assert_equals("key material", keypair.get_key_material(), "");
  }
 
}
