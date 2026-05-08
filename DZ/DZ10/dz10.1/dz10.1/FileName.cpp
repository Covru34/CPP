#include<iostream>
#include<Windows.h>

using namespace std;

double X(int arr[], int size);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int size = 0;
	
	cout << "Введіть розмір масива: \n";
	cin >> size;
	
	int* arr = new int[size];

	cout << "Введіть елементи масиву: \n";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	
	cout << "Середнє арифметичне: " << X(arr, size) << endl;

	delete[] arr;

	return 0;
}

double X(int arr[], int size)
{
	if (size == 0)
		return 0.0;
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}