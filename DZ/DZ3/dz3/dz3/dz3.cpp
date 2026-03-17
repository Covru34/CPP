#include<iostream>
#include<Windows.h>

int main()
{
	using namespace std;
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	char ch;
	cout << "Введіть будь-який символ: \n";
	cin >> ch;
	if (isalpha(ch))
	{
		cout << "Це літера";
	}
	else if (isdigit(ch))
	{
		cout << "Це цифра";
	}
	else if (ispunct(ch))
	{
		cout << "Це пунктуація";
	}


	return 0;
}