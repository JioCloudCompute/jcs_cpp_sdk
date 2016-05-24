#include <string>
using namespace std;
namespace model{
	
	class attach_volume_response
	{
	private:
		string status;
	public:
		detach_volume_response(const string xml_doc);
		void Set_status(string status)
		{
			this->status = status;
		}
		
		string Get_status() const
		{
			return status;
		}

	};

}