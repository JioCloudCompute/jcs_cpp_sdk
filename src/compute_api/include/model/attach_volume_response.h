#include <string>
using namespace std;
namespace model{
	
	class attach_volume_response
	{
	private:
		string status;
		string device;
	public:
		attach_volume_response(const string xml_doc);
		void Set_status(string status)
		{
			this->status = status;
		}
		void Set_device(string device)
		{
			this->device = device;
		}

		string Get_status() const
		{
			return status;
		}
		string Get_device() const
		{
			return device;
		}

	};

}