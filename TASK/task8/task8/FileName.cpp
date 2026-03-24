#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[10] = { 9, 34, 56, 3 ,5, 6, 42, 67, 4, 11 };
	int count = 0;

	cout << "Всі елементи масиву: \n";

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;

		if (arr[i] > 10)
		{
			count++;
		}
	}

	cout << "Кільіксть елементів масиву більші за 10: " << count << endl;

	return 0;
}