#include<iostream>
#include<Windows.h>
using namespace std;

void perfectNumber(int a);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int a;
	

	cout << "Введіть ціле число: \n";
	cin >> a;

	if (a <= 0)
	{
		cout << "Число має бути більше 0";
		return 0;
	}

	perfectNumber(a);
	
	return 0;
}

void perfectNumber(int a)
{

	int sum = 0;

	for (int i = 1;i <= a / 2; i++)
	{
		if (a % i == 0)
		{
			sum += i;
		}
	}

	if (sum == a)
		cout << "Число " << a << " досконале";
	else
		cout << "Число " << a << " не досконале";

}