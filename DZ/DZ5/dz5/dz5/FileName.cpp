#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int a;
	cout << "Введіть любе ціле число до 500: \n";
	cin >> a;

	int sum = 0;

	while (a <= 500)
	{
		sum += a;
		a++;
	}

	cout << "Сума: " << sum;

	return 0;
}