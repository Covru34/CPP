#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#pragma once
using namespace std;
class Subscriber
{
private:
	char* fullName;
	string homePhone;
	string workPhone;
	string mobilePhone;
	string info;

	void setFullName(const char* name) {
		if (fullName) {
			delete[] fullName;
		}
		if (name) {
		}
	}


public:

};

