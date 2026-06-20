#include<iostream>
#include<Windows.h>
using namespace std;

class Student
{
	//Зробимо усі змінні у середині класу public для простоти
	//яКЩО Є ЗМІННА У СЕРИДИНІ КЛАСУ ВОНА ЗВЕТЬСЯ ПОЛЕ КЛАСУ
private:
	char firstName[80];
	char lastName[80];
	int age;
	double avarageMark;

public:
	

	//Це функція у середині класу  - називається метод класу - для ввода інформації про студента, для його вона буде викликатис
	void setInfo()
	{
		cout << "Вкажіть призвіще: ->";
		cin.getline(lastName, 80, '\n');
		cout << "Вкажіть ім'я: ->";
		cin.getline(firstName, 80, '\n');
		cout << "Вкажіть вік: ->";
		cin >> age;
		cout << "Вкажіть середню оцінку: ->";
		cin >> avarageMark;
	}
	void displayInfo()
	{
		cout << "\n---Ви вказали інформацію про студента---\n";
		cout << lastName << " " << firstName << "\n";
		cout << "Вік: " << age << "\t" << "Середня оцінка: " << avarageMark << "\n";
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "---Вчимося працювати із об'єктами---";

 	// на С++ придумали класи, клас це механізм для створнггя об'єктів
	//клас дуже схожий на структуру, У класі є специфікатори доступу:
	// private, public, protected. Алгоритм дій: 
	// 1. описуємо сам клас
	// 2. вказуємо що включає клас
	// 3. На основі данного класу створюємо змінні

	//На основі класі Student робимо змінну matviy - це уже об'єкт класу
	//Можна змінну класу називати - Екземпляри класу
	Student matviy;
	// public - дає можливість доступу до змінних класу - полів класу
	
	//strcpy_s(matviy.lastName, "Софія"); //це проблема бо клас має забороняти звертатися на пряму

	matviy.setInfo();//записуємо дані матвія
	matviy.displayInfo();// виводимо дані матвія

	

}