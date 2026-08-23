#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

// Комопзиція - коли 1 клас включає в себе інший клас - його об'єкт
// Тобто клас, який включакє в себе інший клас без нього не може існувати

class Engine 
{
public:
	void start()
	{
		cout << "Двигун заведено\n";
	}
};
class Car
{
private:
	Engine engine;
public:
	void start()
	{
		engine.start();
	}
};

class Student
{
private:
	string name;
public:
	Student(string n) : name(n) {}
	void info()
	{
		cout << "ПІБ: " << name << '\n';
	}

	void setName(string name)
	{
		this->name = name;
	}
};

class Group
{
private:
	vector<Student*> students; 
public:
	void addStudent(Student* s)
	{
		students.push_back(s);
	}
	void viewList()
	{
		for (Student* s : students)
		{
			s->info(); // Показуємо інформацію про певного студента в групі
		}
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "--- Композиція ---\n";
	//Car car;
	//car.start();

	cout << "-- Агрегація --\n";
	Student peter("Мельник Петро Васильович");
	Student vova("Салько Володимер Павлович");
	Student oleh("Жгут Олег Юзківич");
	Group g;
	g.addStudent(&peter);
	g.addStudent(&vova);
	g.addStudent(&oleh);
	cout << "Група студентів\n";
	g.viewList();

	vova.setName("Рябий Ваоерій Маркович");

	cout << "--У студента змінилася інфомрація--\n";
	g.viewList();

	return 0;
}