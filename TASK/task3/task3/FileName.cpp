#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[5] = { 13, 9, 6, 54, 42 };

	cout << "Всі Числа: ";

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "Всі числа більше 10: ";

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > 10)
			cout << arr[i] << "\t";
	}
		
		
	
	return 0;
}