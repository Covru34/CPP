#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[5] = { 42, 7, 34, 9, 12 };

	cout << "Всі елементи масива: \n";

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\n";
	}

	cout << "Парні елементи: \n";

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] % 2 == 0)
			cout << arr[i]<<"\n";
	}

	return 0;
}