#include "src/XMLParser.h"

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

void error_report_parse(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());

	XMLNode *RootNode = doc.FirstChild();

	XMLElement *Element = RootNode->NextSiblingElement();
	if(Element == NULL)
		return;

	for(int i = 0;i<3;i++)
	{
		if(Element != NULL )Element = Element->FirstChildElement();
		else {cout<<"Error Occured while Parsing XML or Server Didn't Respond";return;}

	}

	if(Element != NULL & Element->GetText() !=NULL)
	{
		cout<<Element->GetText()<<endl;Element=Element->NextSiblingElement();
	}
	else 
		return;

	if(Element->GetText() != NULL)
		cout<<Element->GetText();
	else
		cout<<"Error Parsing XML";

}
