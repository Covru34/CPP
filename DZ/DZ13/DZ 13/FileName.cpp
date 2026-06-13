#include<iostream>
#include<Windows.h>
#include<cstring>
using namespace std;

void deleteByIndex(char str[], int index);

void deletAllChar(char str[], char ch);

void insertChar(char str[], int pos, char ch, int maxSize);

void replacement(char str[]);

void accountant(char str[], int ch, int cout);

void accountant2(char str[], int letters, int digits, int other);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	char str[20] = "Helo!";
	insertChar(str, 3, 'l', 20);   
	cout << str << endl;          
	return 0;

}

void deleteByIndex(char str[], int index)
{
	int len = strlen(str);
	if (index < 0 || index >= len)
	for(int i = index; i < len - 1; i++)
		str[i] = str[i + 1];
	str[len - 1] = '\0';
}

void deletAllChar(char str[], char ch)
{
	int i = 0, j = 0;
	while (str[i] != '\0') {
		if (str[i] != ch)
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void insertChar(char str[], int pos, char ch, int maxSize)
{
	int len = strlen(str);
	if (pos < 0 || pos > len || len + 1 >= maxSize) return;
	for (int i = len; i >= pos; i--)
		str[i + 1] = str[i];
	str[pos] = ch;
}

void replacement(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '.')
			str[i] = '!';
}

void accountant(char str[], int ch, int cout)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ch)
			cout++;
}

void accountant2(char str[],int letters, int digits, int other)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])) 
			letters++;
		else if (isdigit(str[i]))  
			digits++;
		else
			others++;
}