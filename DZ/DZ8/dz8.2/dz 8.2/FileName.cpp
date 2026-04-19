#include<iostream>
#include<Windows.h>
#include<cstdlib> 
#include<ctime>  
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	srand(time(0));

	int n1 = rand() % 100;
	int n2 = rand() % 100;
	int n3 = rand() % 100;
	int n4 = rand() % 100;
	int n5 = rand() % 100;


	int arr[5] = {n1, n2, n3, n4, n5 };
	int min = arr[0];
	int max = arr[0];

	cout << "Масив: ";

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ", ";
	}

	cout << endl;

	for (int i = 0;i < 5;i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	for (int i = 0;i < 5;i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	cout << "Мінімальне число в масиві: " << min << "\nМаксимальне число в масиві: " << max;

	return 0;
}