#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int scr[5] = { 10, 20, 30, 40, 50 };
	int dsr[5];

	int* p = scr + 5 - 1;
	int* q = dsr;

	while (p >= scr)
	{
		*q = *p;
		p--;
		q++;
	}
	
	for (int i = 0;i < 5;i++)
	{
		cout << scr[i] << "\t";
	}
	cout << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << dsr[i] << "\t";
	}
	return 0;
}