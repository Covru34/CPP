#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int number;
	cout << "Введіть число: \n";
	cin >> number;

	int digit;
	int sum = 0;

	while(number > 0)
	{
		digit = number % 10;
		sum += digit;
		number /= 10;
	}

	cout << "Сума цифр числа: " << sum << endl;

	return 0;
}