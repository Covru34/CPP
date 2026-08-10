#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int n;
	cout << "Введіть розмір масиву: \n";
	cin >> n;

	int* arr1 = new int[n];
	int* ptr1 = arr1;
	int count = 0;

	cout << "Введіть " << n << " елементів:\n";
	for (int i = 0; i < n; i++)
	{
		cin >> *ptr1;

		// Перевірка на просте число
		bool isPrime = true;
		if (*ptr1 <= 1) {
			isPrime = false;
		}
		else {
			for (int j = 2; j * j <= *ptr1; j++) {
				if (*ptr1 % j == 0) {
					isPrime = false;
					break;
				}
			}
		}

		if (isPrime) {
			count++;
		}
		ptr1++;
	}

	int* arr2 = new int[count];
	int* ptr2 = arr2;

	ptr1 = arr1;

	for (int i = 0; i < n; i++)
	{
		// Повторна перевірка для копіювання
		bool isPrime = true;
		if (*ptr1 <= 1) {
			isPrime = false;
		}
		else {
			for (int j = 2; j * j <= *ptr1; j++) {
				if (*ptr1 % j == 0) {
					isPrime = false;
					break;
				}
			}
		}

		if (isPrime) {
			*ptr2 = *ptr1; //  Зберігаємо ЗНАЧЕННЯ
			ptr2++;        // Зсуваємо ptr2 тільки якщо скопіювали
		}
		ptr1++;
	}

	delete[] arr1;
	arr1 = nullptr;
	ptr1 = nullptr;

	ptr2 = arr2;

	for (int i = 0;i < count;i++)
	{
		cout << i + 1 << ". " << *ptr2 << '\n';
		ptr2++;
	}

	delete[] arr2;
	arr2 = nullptr;
	ptr2 = nullptr;

	return 0;
}