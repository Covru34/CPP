#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	bool found = false;
	int A;
	cout << "Введіть ціле число: \n";
	cin >> A;

	for (int B = 1; B * B <= A; B++)
	{
		if (A % (B * B) == 0 && A % (B * B * B) != 0)
		{
			cout << B << " ";
			found = true;
		}
	}

	if (!found)
	{
		cout << "Немає таких B";
	}

	return 0;
}