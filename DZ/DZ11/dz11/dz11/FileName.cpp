#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	const int n = 5;
	int arr1[n] = { 1, 3, 5, 7, 9 };
	int arr2[n];

	int* a1 = arr1;
	int* a2 = arr2;

	while (a1 < arr1 + n) {
		*a2 = *a1;
		a1++;
		a2++;
	}

	cout << "arr2: ";

	for (int i = 0; i < n;i++)
	{
		cout << arr2[i] << " ";
	}

	return 0;
}