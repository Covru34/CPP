#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

class Contact
{
private:
	char* fullName;
	string homePhone; 
	string workPhone;
	string mobilePhone;
	string additionalInfo;
public:
	char* fullName = nullptr;
};

