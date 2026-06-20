#include<iostream>
#include<Windows.h>
using namespace std;

// ключенове слова - struct - для оголошення прототипу структури
struct Student // Student - це можна сказати наш вланий тип даних
{
	char name[80]; // ПІБ студента
	int mark; //оцінка
	int age; // вік студента
};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "Усіх із св'ятом!\n";
	//масив - це набір однотипних даних
	//наприклад int list[10]; // десять числе цілого типу
	//Структура - це набрі даних, який може містити різні
	//типи даних.
	//Для того, щоб працювати із структурою потрібно на початку
	//оголосоити прототип структури 
	// (Щось схоже до прототипу функції). 
	Student ivan;
	ivan.age = 12;
	ivan.mark = 4.5;
	strcpy_s(ivan.name, "Марко Фван Петрович");

	cout << ivan.name << endl
		<< "Вік: " << ivan.age << "\tОцінка: "
		<< ivan.mark << "\n";
	return 0;
}
