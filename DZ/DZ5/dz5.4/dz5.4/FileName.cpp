#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int k;
	cout << "Введіть варіант: \n";
	cin >> k;

	cout << k << " * 1 = " << k * 1 << endl;
	cout << k << " * 2 = " << k * 2 << endl;
	cout << k << " * 3 = " << k * 3 << endl;
	cout << k << " * 4 = " << k * 4 << endl;
	cout << k << " * 5 = " << k * 5 << endl;
	cout << k << " * 6 = " << k * 6 << endl;
	cout << k << " * 7 = " << k * 7 << endl;
	cout << k << " * 8 = " << k * 8 << endl;
	cout << k << " * 9 = " << k * 9 << endl;
	cout << k << " * 10 = " << k * 10 << endl;

	return 0;
}