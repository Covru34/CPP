#include<iostream>
#include<Windows.h>
using namespace std;

class Animal
{
protected:
	string name; 
public:
	Animal(string n) : name(n) {};
	Animal()
	{
		name = "Emply";
	}

	void eat()
	{
		cout << name << " їсть\n";
	}

	virtual void makeSound()
	{
		cout << "Якийсь звук\n";
	}

};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}; // Викликаємо конструктор батьківського класу

	void makeSound() override
	{
		cout << name << " гавкає\n";
	}
};

class Raccoon : public Animal
{
public:
	Raccoon(string name) : Animal(name) {};

	void makeSound() override
	{
		cout << name << " муркає\n";
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "--- Наслідування, Агренація і Композиція С++ ---\n";

	//Animal cat("Кіт");
	//cat.eat();
	//cat.makeSound();

	//Dog myDog("Собака");
	//myDog.makeSound();

	//Raccoon semen("Семен");
	//semen.makeSound();

	Animal* list[5];
	list[0] = new Dog("Кусачий");
	list[1] = new Raccoon("Вонючий");
	list[2] = new Dog("Рекс");
	list[3] = new Raccoon("Бездомний");
	list[4] = new Dog("Злий");

	for (int i = 0; i < 5; i++)
		list[i]->makeSound();

	return 0;
}