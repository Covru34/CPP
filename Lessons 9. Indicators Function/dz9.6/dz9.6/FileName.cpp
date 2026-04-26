#include<iostream>
#include<Windows.h>
using namespace std;

int searchArray(int n, int array[], int key);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int n;
	cout << "Введіть кільскість елементів масиву: \n";
	cin >> n;

	int* array = new int[n];
	cout << "Введіть відсортований(бінарний) масив: \n";
	for (int i = 0; i < n;i++)
	{
		cout << "array[" << i << "]: ";
		cin >> array[i];
	}

	int key;
	cout << "Введіть ключ для пошуку: \n";
	cin >> key;

	int result = searchArray(n, array, key);

	if (result != -1)
		cout << "Знайдено індекс: " << result << endl;
	else
		cout << "Елемент не знайдено" << endl;

	return 0;
}

int searchArray(int n, int array[], int key)
{
	int lo = 0;
	int hi = n;

	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (array[mid] == key)
			return mid;
		else if (array[mid] < key)
			lo = mid + 1;
		else if (array[mid] > key)
			hi = mid - 1;
	}
	return -1;
}