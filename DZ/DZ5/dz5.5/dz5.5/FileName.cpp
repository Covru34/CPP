#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	for ( int i = 100;  i <= 999; i++)
	{
		int number1 = i / 100;
		int number2 = i / 10 % 10;
		int number3 = i % 10;
		 
		if (number1 == number2 || number2 == number3 || number3 == number1)
		{
			cout << i << " ";
		}
	}

	return 0;
}