#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[5] = { 42, 34, 67, 12, 89};
	int sum = 0;

	cout << "Всі елементи: \n";

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "Сума всіх елементів: \n";

	for (int i = 0; i < 5; i++)
	{
		sum += arr[i];
	}

	cout << sum;

	return 0;
}