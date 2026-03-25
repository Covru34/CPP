#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int a[7];
	cout << "Введіть 7 цілих чисел: \n";
	
	for (int i = 0; i < 7; i++)
	{
		cin >> a[i];
	}
	
	int max = a[0];

	for(int i = 0; i < 7; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	cout << "Найбільше число: " << max;

	return 0;
}
