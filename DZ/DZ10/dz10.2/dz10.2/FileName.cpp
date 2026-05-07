#include<iostream>
#include<Windows.h>
using namespace std;

void countElements(int arr[], int size, int& positive, int& negative, int& zero);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int size, pos, neg, zer;
	
	cout << "Введіть розмір масиву: \n";
	cin >> size;

	int* arr = new int[size];

	cout << "Введіть його елементи: \n";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	countElements(arr, size, pos, neg, zer);

	cout << "Додатних елементiв: " << pos << endl;
	cout << "Вiд'ємних елементiв: " << neg << endl;
	cout << "Нульових елементiв: " << zer << endl;

	delete[] arr;

	return 0;
}

void countElements(int arr[], int size, int& positive, int& negative, int& zero)
{
	positive = 0;
	negative = 0;
	zero = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
			positive++;
		else if (arr[i] < 0)
			negative++;
		else zero++;
	}
}