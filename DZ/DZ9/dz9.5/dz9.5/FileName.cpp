#include<iostream>
#include<Windows.h>
using namespace std;

int searchArray(int array[], int n, int key);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	
	int n = 0;
	cout << "Введіть кільскість елементів у масиві: \n";
	cin >> n;

	int* array = new int[n];
	cout << "Введіть " << n << " елементів масиву: \n";

	for (int i = 0; i < n; i++)
	{
		cout << "масив[" << i << "]: ";
		cin >> array[i];
	}

	int key;
	cout << "Введіть ключ для пошуку: ";
	cin >> key;

	int result = searchArray(array, n, key);

	if (result != -1)
		cout << "Знайдено на індексі: " << result << endl;
	else
		cout << "Елемент не знайдено" << endl;

	return 0;
}

int searchArray(int array[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == key)
			return i;
	}
	return -1;
}