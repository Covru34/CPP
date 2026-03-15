#include "iostream"
#include "Windows.h"
#include "cmath"

void main()
{
	using namespace std;
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	cout << "Введіть прше число: \n";
	int a;
	cin >> a;
	cout << "Введіть друге число: \n";
	int b;
	cin >> b;

	cout << "a = " << a << "\n";
	cout << "b = " << b << "\n"; 
	cout << "a + b = " << a + b << "\n";
	cout << "a - b = " << a - b << "\n";
	cout << "a * b = " << a * b << "\n";
	cout << "a / b = " << a / b << "\n";
	cout << "a // b = " << pow(a, b) << "\n";

}