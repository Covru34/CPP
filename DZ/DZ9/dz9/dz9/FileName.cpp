#include<iostream>
#include<Windows.h>
using namespace std;

void stepin();

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	stepin();

	return 0;
}

void stepin()
{
	int a, s;
	int sum = 1;
	cout << "Введіть основу степіння: \n";
	cin >> a;
	cout << "Введіть степінь: \n";
	cin >> s;



	for (int i = 0; i < s; i++)
	{
		sum *= a;
	}

	cout << sum;
}