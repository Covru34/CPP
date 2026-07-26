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

	if (number % 2 == 0)
	{
		cout << "Це парне число!\n";
	}
	else if (number % 2 != 0)
	{
		cout << "Це число не парне!";
	}
	return 0;
}