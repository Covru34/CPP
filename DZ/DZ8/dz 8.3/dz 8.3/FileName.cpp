#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[12];
	int d1;
	int d2;
	
	cout << "Введіть дохід компанії за 1 рік(12 місяців): \n";
	for (int i = 0; i < 12; i++)
	{
		cout << "Місяць " << i + 1 << " : ";
		cin >> arr[i];
	}

	cout << "Введіть діапазон між місяцями(наприклад 3 і 6): \n";
	cin >> d1;
	cin >> d2;

	int start = d1 - 1;
	int end = d2 - 1;

	int min = arr[start];
	int max = arr[start];
	int minIndex = start;
	int maxIndex = start;


	for (int i = start; i <= end; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minIndex = i;
		}
	}

	for (int i = start; i <= end; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxIndex = i;
		}
	}

	cout << "Місяць з мінімальним прибутком: " << minIndex + 1 << endl;
	cout << "Місяць з максимальним прибутком: " << maxIndex + 1 << endl;
	return 0;
}