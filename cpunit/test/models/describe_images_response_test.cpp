
#include <cpunit>
#include <model/describe_images_response.hpp>

#define MYUNSIGNED(x) static_cast<unsigned>(x)

namespace DescribeImagesResponseTest {
  using namespace cpunit;
#define USTR CPUNIT_STR

  CPUNIT_TEST(DescribeImagesResponseTest, test0) {
    const std::string myxml;
    const model::describe_images_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "");
    const std::vector<model::image>& images = resp.get_images();
    assert_equals("size", images.size(), static_cast<size_t>(0));
  }

  CPUNIT_TEST(DescribeImagesResponseTest, test1) {
    const string myxml("<DescribeImagesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaeb</requestId><imagesSet><item><blockDeviceMapping><volumeSize>8</volumeSize><deviceName>/dev/vda</deviceName><deleteOnTermination>False</deleteOnTermination><snapshotId>snap-0001</snapshotId><encrypted>True</encrypted></blockDeviceMapping><name>Ubuntu 1.0</name><isPublic>true</isPublic><imageId>jmi-784567</imageId><imageState>available</imageState><architecture>x86_64</architecture><imageType>machine</imageType></item></imagesSet></DescribeImagesResponse>");
    const model::describe_images_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaeb");
    const std::vector<model::image>& images = resp.get_images();
    assert_equals("size", images.size(), static_cast<size_t>(1));

    const model::image& i0 = images[0];
    const model::block_device bd = i0.get_block_device_mapping();
    assert_equals("device name", bd.deviceName, "/dev/vda");
    assert_equals("delete_on_termination", bd.deleteOnTermination, false);
    assert_equals("snapshotid", bd.snapshotId, "snap-0001");
    assert_equals("volume size", bd.volumeSize, MYUNSIGNED(8));

    assert_equals("image id", i0.get_image_id(), "jmi-784567");
    assert_equals("is public", i0.get_is_public(), true);
    assert_equals("name", i0.get_name(), "Ubuntu 1.0");
    assert_equals("image state", i0.get_image_state(), "available");
    assert_equals("image arch", i0.get_architecture(), "x86_64");
    assert_equals("image type", i0.get_image_type(), "machine");
  }

  CPUNIT_TEST(DescribeImagesResponseTest, test2) {
    const string myxml("<DescribeImagesResponse xmlns=\"https://compute.ind-west-1.jiocloudservices.com/doc/2016-03-01/\"><requestId>req-722680ec-57a8-43ce-afc1-414720b0aaec</requestId><imagesSet><item><blockDeviceMapping><volumeSize>20</volumeSize><deviceName>/dev/vda</deviceName><deleteOnTermination>False</deleteOnTermination><snapshotId>snap-0023</snapshotId><encrypted>True</encrypted></blockDeviceMapping><name>Ubuntu-14.0</name><isPublic>true</isPublic><imageId>jmi-784989</imageId><imageState>available</imageState><architecture>x86_64</architecture><imageType>machine</imageType></item><item><blockDeviceMapping><volumeSize>8</volumeSize><deviceName>/dev/vda</deviceName><deleteOnTermination>False</deleteOnTermination><snapshotId>snap-0001</snapshotId><encrypted>True</encrypted></blockDeviceMapping><name>Ubuntu-16.0</name><isPublic>false</isPublic><imageId>jmi-9eafbcd</imageId><imageState>available</imageState><architecture>x86_64</architecture><imageType>machine</imageType></item></imagesSet></DescribeImagesResponse>");
    const model::describe_images_response resp(myxml);
    assert_equals("Request id", resp.get_request_id(), "req-722680ec-57a8-43ce-afc1-414720b0aaec");
    const std::vector<model::image>& images = resp.get_images();
    assert_equals("size", images.size(), static_cast<size_t>(2));

    {
    const model::image& i0 = images[0];
    const model::block_device bd = i0.get_block_device_mapping();
    assert_equals("device name", bd.deviceName, "/dev/vda");
    assert_equals("delete_on_termination", bd.deleteOnTermination, false);
    assert_equals("snapshotid", bd.snapshotId, "snap-0023");
    assert_equals("volume size", bd.volumeSize, MYUNSIGNED(20));

    assert_equals("image id", i0.get_image_id(), "jmi-784989");
    assert_equals("is public", i0.get_is_public(), true);
    assert_equals("name", i0.get_name(), "Ubuntu-14.0");
    assert_equals("image state", i0.get_image_state(), "available");
    assert_equals("image arch", i0.get_architecture(), "x86_64");
    assert_equals("image type", i0.get_image_type(), "machine");
    }
    {
    const model::image& i0 = images[1];
    const model::block_device bd = i0.get_block_device_mapping();
    assert_equals("device name", bd.deviceName, "/dev/vda");
    assert_equals("delete_on_termination", bd.deleteOnTermination, false);
    assert_equals("snapshotid", bd.snapshotId, "snap-0001");
    assert_equals("volume size", bd.volumeSize, MYUNSIGNED(8));

    assert_equals("image id", i0.get_image_id(), "jmi-9eafbcd");
    assert_equals("is public", i0.get_is_public(), false);
    assert_equals("name", i0.get_name(), "Ubuntu-16.0");
    assert_equals("image state", i0.get_image_state(), "available");
    assert_equals("image arch", i0.get_architecture(), "x86_64");
    assert_equals("image type", i0.get_image_type(), "machine");
    }
  }
 
}
