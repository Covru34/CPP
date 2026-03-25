#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "Введіть суму продажів для трьох менеджерів($): \n";
	double s1, s2, s3;
	double sal1, sal2, sal3;

	cin >> s1;
	cin >> s2;
	cin >> s3;

	if (s1 <= 500)
		sal1 = 200 + s1 * 0.03;
	else if (s1 <= 1000)
		sal1 = 200 + s1 * 0.05;
	else if (s1 > 1000)
		sal1 = 200 + s1 * 0.08;

	if (s2 <= 500)
		sal2 = 200 + s2 * 0.03;
	else if (s2 <= 1000)
		sal2 = 200 + s2 * 0.05;
	else if (s2 > 1000)
		sal2 = 200 + s2 * 0.08;

	if (s3 <= 500)
		sal3 = 200 + s3 * 0.03;
	else if (s3 <= 1000)
		sal3 = 200 + s3 * 0.05;
	else if (s3 > 1000)
		sal3 = 200 + s3 * 0.08;

	if (sal1 > sal2 && sal1 > sal3)
		sal1 += 200;
	else if (sal2 > sal1 && sal2 > sal3)
		sal2 += 200;
	else if (sal3 > sal1 && sal3 > sal2)
		sal3 += 200;

	cout << "Зарплата менеджерів за місяць:\n Менеджер №1 заробив " << sal1 << "$\n Менеджер №2 заробив " << sal2 << "$\n Менеджер №3 заробив " << sal3 << "$";
		
	return 0;
}