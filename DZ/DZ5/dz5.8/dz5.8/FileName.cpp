#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int A;
	cout << "Введіть ціле число: \n";
	cin >> A;

	return 0;
}