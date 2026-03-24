#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[5] = { 42, 34, 67, 10, 1488 };
	int max = arr[0];

	cout << "Всі елементи масиву: \n";

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;

		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	cout << "Найбільший елемент масиву: " << max << endl;

	return 0;
}