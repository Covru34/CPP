#include<iostream>
#include<Windows.h>
#include<cmath>
using namespace std;

bool isLeapYear(int year);

int daysInMonth(int month, int year);

long long dateToDays(int day, int month, int year);

long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int d1, m1, y1, d2, m2, y2;
	cout << "Введіть першу дату (день місяць рік): ";
	cin >> d1 >> m1 >> y1;
	cout << "Введіть другу дату (день місяць рік): ";
	cin >> d2 >> m2 >> y2;

	cout << "Рік " << y1 << (isLeapYear(y1) ? " високосний" : " не високосний") << endl;
	cout << "Різниця: " << dateDifference(d1, m1, y1, d2, m2, y2) << " днів" << endl;

	return 0;
}

bool isLeapYear(int year)
{
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year)
{
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && isLeapYear(year))
		return 29;
	return days[month - 1];
}

long long dateToDays(int day, int month, int year) 
{
	long long totalDays = 0;
	for (int y = 1; y < year; ++y) 
	{
		totalDays += isLeapYear(y) ? 366 : 365;
	}
	for (int m = 1; m < month; ++m) 
	{
		totalDays += daysInMonth(m, year);
	}
	totalDays += day;
	return totalDays;
}

long long dateDifference(int d1, int m1, int y1,
	int d2, int m2, int y2)
{
	return abs(dateToDays(d2, m2, y2) - dateToDays(d1, m1, y1));
}