#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	int a;
	int b;
	cout << "Введіть два числа: \n";
	cin >> a;
	cin >> b;

	if (a > b)
	{
		cout << a << " > " << b << endl;
	}
	else if (b > a)
	{
		cout << b << " > " << a << endl;
	}
	else if (a == b)
	{
		cout << a << " = " << b << endl;
	}

	return 0;
}