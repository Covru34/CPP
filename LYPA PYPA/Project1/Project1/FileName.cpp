#include <iostream>
#include <string>
#include <Windows.h>
#include <cstring>
using namespace std;

void printArr(string arr[], int N);
void inputArr(string arr[], int N);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "Робота з масивами про поні🤣😂🤣😂🤣\n\n";
	const int N = 6;
	string MLP[N];// = { "Twilight Sparkle", "Pinkie Pie", "AppleJack", "Fluttershy", "Rainbow Dash", "Rarity" };

	cout << "Введіть головну шестірку: \n";
	inputArr(MLP, N);
	cout << "***Головна шестірка***\n";
	printArr(MLP, N);

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