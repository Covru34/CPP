#include<iostream>
#include<Windows.h>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Створили персону\n";
	}
};
class Faculty : virtual public Person
{
public:
	Faculty()
	{
		cout << "Створили факультет\n";
	}
};
class Student : virtual public Person
{
public:
	Student()
	{
		cout << "Створили студента\n";
	}
};
class TA : public Faculty, Student
{
public: 
	TA()
	{
		cout << "ТА конструктор\n";
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "Віртуальний базовий клас\n";
	//Person p;
	//Faculty f;
	//Student s;
	TA ta;

	return 0; 
}