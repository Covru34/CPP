#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int x;
	int y;
	cout << "Введіть х: \n";
	cin >> x;
	cout << "Введіть у: \n";
	cin >> y;

	int stepin = 1;

	for (int i = 0; i < y; i++)
	{
		stepin *= x;
	}

	cout << "Результат: " << stepin;

	return 0;
}