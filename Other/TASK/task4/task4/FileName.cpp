#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int a;
	int b;
	int c;

	cout << "Введіть 3 числа: \n";
	cin >> a;
	cin >> b;
	cin >> c;

	if (a >= b && a >= c)
	{
		cout << "Число " << a << " є найбільшим\n";
	}
	else if (b >= a && b >= c)
	{
		cout << "Число " << b << " є найбільшим\n";
	}
	else if (c >= a && c >= b)
	{
		cout << "Число " << c << " є найбільшим\n";
	}

	return 0;
}