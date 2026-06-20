#include <iostream>
#include <string>
#include <Windows.h>
#include <cstring>
using namespace std;

const int N = 6;
const int n = 4, m = 2;

void printArr(string arr[], int N);
void inputArr(string arr[], int N);
void inputDoubleArr(string arr[][m], int n);
void printDoubleArr(string arr[][m], int n);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "Робота з масивами про поні🤣😂🤣😂🤣\n\n";
	
	string DoubleMLP[n][m];
	string MLP[N];// = { "Twilight Sparkle", "Pinkie Pie", "AppleJack", "Fluttershy", "Rainbow Dash", "Rarity" };

	//cout << "Введіть головну шестірку: \n";
	//inputArr(MLP, N);
	//cout << "\n***Головна шестірка***\n";
	//printArr(MLP, N);
	cout << "\n***Розподіліть поні по їхнім расам***\n";
	inputDoubleArr(DoubleMLP, n);
	cout << "\n***Результат***\n";
	printDoubleArr(DoubleMLP, n);

	return 0;
}

void printArr(string arr[], int N)
{
	for (int i = 0; i < N; i++)
	{

		cout << i + 1<< ". " <<arr[i] << "\n";

	}
}

void inputArr(string arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Поні " << i + 1 << ": ";
		getline(cin, arr[i]);
	}
}

void inputDoubleArr(string arr[][m], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Елемент [" << i << "][" << j << "]: ";
			getline(cin, arr[i][j]);
		}
	}
}

void printDoubleArr(string arr[][m], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}