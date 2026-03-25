#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "Введіть чотирьох значне число: \n";
	int a;
	cin >> a;

	if (a < 1000 || a > 9999)
	{
		cout << "Ви ввели не чотирьох значне число\n";
		return 0;
	}

	int digit1 = a / 1000;
	int digit2 = (a / 100) % 10;
	int digit3 = (a / 10) % 10;
	int digit4 = a % 10;

	cout << digit2 << digit1 << digit4 << digit3;

	return 0;
}