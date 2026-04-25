#include<iostream>
#include<Windows.h>
using namespace std;

bool luckyNumber(int num);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int num;
	cout << "Введіть число: \n";
	cin >> num;

	luckyNumber(num);

	bool result = luckyNumber(num);

	if (result)
		cout << "Число щасливе";
	else
		cout << "Число не щасливе";


	return 0;
}

bool luckyNumber(int num)
{
	if (num < 100000 || num > 999999)
		return false;

	int a = num / 100000;
	int b = (num / 10000) % 10;
	int c = (num / 1000) % 10;
	int d = (num / 100) % 10;
	int e = (num / 10) % 10;
	int f = num % 10;
	
	return (a + b + c) == (d + e + f);
}