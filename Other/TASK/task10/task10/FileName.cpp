#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int a;
	int b;
	char c;

	cout << "Введіть перше число: \n";
	cin >> a;
	cout << "Введіть друге число: \n";
	cin >> b;
	cout << "Введіть дію(*, /, +, -, %): \n";
	cin >> c;

	if (c == '*')
	{
		cout << a << " * " << b <<  "= " << a * b << endl;
	}
	else if (c == '/')
	{
		cout << a << " / " << b << " = " << a / b << endl;
	}
	else if (c == '+')
	{
		cout << a << " + " << b << " = " << a + b << endl;
	}
	else if (c == '-')
	{
		cout << a << " - " << b <<  " = " << a - b << endl;
	}
	else if (c == '%')
	{
		cout << a << " % " << b << " = " << a % b << endl;
	}
	else
	{
		cout << "Ви ввели щось не то";
	}

	return 0;
}