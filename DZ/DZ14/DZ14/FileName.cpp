#include<iostream>
#include<Windows.h>
#include <string>
#include <cctype>
using namespace std;

bool bigLetter(string password);

bool smallLetter(string password);

bool hasDigit(string password);

bool hasLenght(string password);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	string password;

	cout << "Введіть пароль: \n";
	cin >> password;

	bool valid = true;

	if (!bigLetter(password))
	{
		cout << "Не вистачає великих літер!" << endl;
		valid = false;
	}

	if (!smallLetter(password))
	{
		cout << "Не вистачає маленьких літер!" << endl;
		valid = false;
	}

	if (!hasDigit(password))
	{
		cout << "Не вистачає цифр!" << endl;
		valid = false;
	}

	if (!hasLenght(password))
	{
		cout << "Пароль занадто короткий (мінімум 8 символів)!" << endl;
		valid = false;
	}

	if (valid)
		cout << "Пароль відповідає всім вимогам!" << endl;

}

bool bigLetter(string password)
{
	for (int i = 0; i < password.length();i++)
		if (isupper(password[i])) // перевіряємо наявність великих символів
			return true;
	return false;
}

bool smallLetter(string password)
{
	for (int i = 0; i < password.length();i++)
		if (islower(password[i])) // перевіряємо наявність маленьких символів
			return true;
	return false;
}

bool hasDigit(string password)
{
	for (int i = 0; i < password.length();i++)
		if (isdigit(password[i])) // перевіряємо наявність цифр
			return true;
	return false;
}

bool hasLenght(string password)
{
	return password.length() >= 8;
}