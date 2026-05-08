#include<iostream>
#include<Windows.h>
using namespace std;

int gcd(int a, int b);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int a = 48, b = 18;
	cout << "НСД(" << a << ", " << b << ") = " << gcd(a, b) << endl;
	a = 100; b = 75;
	cout << "НСД(" << a << ", " << b << ") = " << gcd(a, b) << endl;

	return 0;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
