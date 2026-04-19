#include<iostream>
#include<Windows.h>
using namespace std;
// якщо число відємне то воно буде додатнє
// якщо воно додатнє то буде без змін
void Abs(int &a);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "---Використання функції із вказіниками та посиланнями---\n";
	int p = -5;
	
	cout << "Адреса числа p: " << &p << endl;
	Abs(p);
	cout << "Модуль числа: " << p << endl;
}

void Abs(int &a)
{
	cout << "Адреса числа у функції: " << &a << endl;
	if (a < 0)
		a = -a;
}