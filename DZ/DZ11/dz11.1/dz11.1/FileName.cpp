#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[5] = { 10, 20, 30, 40, 50 };
	int* left = arr;
	int* right = arr + 5 - 1;

	for (int i = 0; i < 5;i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	while (left < right)
	{
		int tmp = *left;  // зберігаємо значення лівого
		*left = *right; // на місці лівого записуємо значення правого
		*right = tmp; // на місці правого записуємо збережене значення лівого - tmp
		left++;
		right--;
	}

	for (int i = 0; i < 5;i++)
	{
		cout << arr[i] << "\t";
	}

	return 0;
}