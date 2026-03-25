#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	double data1 = 0;
	double data2 = 0;

	cout << "Введіть дві любі дати(11.11.2011): \n";
	cout << "Перша: \n";
	cin >> data1;
	cout << "Дуга: \n";
	cin >> data2;

	cout << data1 << data2;

	return 0;
}