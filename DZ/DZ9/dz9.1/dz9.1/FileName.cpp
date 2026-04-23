#include<iostream>
#include<Windows.h>
using namespace std;

void sumDiapazon();

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	sumDiapazon();

	return 0;
}

void sumDiapazon()
{
	int a, b;
	int sum = 0;
	cout << "Введіть перше ціле число: \n";
	cin >> a;
	cout << "Введіть друге ціле число: \n";
	cin >> b;

	if (a > b) std::swap(a, b);

	for (int i = a; i <= b;i++)
	{
		sum += i;
	}
	cout << "Сума діапазона чисел між " << a << " та " << b << " : " << sum;
}