#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

class Car
{
private:
	string carNumber; // номер автомобілля 
	string* fines;// список штрафів
	int finesCount; // кількістиь штрафів
public:
	Car(string number = "")
	{
		carNumber = number;
		finesCount = 0;
		fines = nullptr;
	}


};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);



	return 0;
}