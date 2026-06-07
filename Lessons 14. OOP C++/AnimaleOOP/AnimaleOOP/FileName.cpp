#include<iostream>
#include<Windows.h>
#include<cstring>
using namespace std;

class Animal
{
private:
	char name[80];
	int age;
	double weight;
	char breed[50]; // порода тваринки
public:
	// для початкової ініалізаціх об'єкта потрібно будувати конструктор 
	// конструктор співпадає із назвою класу
	// цей конструктор - по замовчуванню - виклткається автоматично
	Animal() // це метод класу, але є він спеціальний і звеця конструктор
	{
		strcpy_s(name, "Назва_тварини");
		strcpy_s(breed, "Порода_тварини");
		age = 0;
		weight = 0;
	}
	//робимо конструктор з параметрами
	Animal(const char* name, const char* breed, int age, double weight) //це перегружений конструктор - як функція - фле це метод
	{
		strcpy_s(this->name, name);
		strcpy_s(this->breed, breed);
		this->age = age;
		this->weight = weight;
	}

	void print()
	{
		cout << "Назва: " << name << endl;
		cout << "Порода: " << breed << endl;
		cout << "Вік: " << age << endl;
		cout << "Вага: " << weight << endl << endl;
		
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "---Бдемо працювати з тваринами---\n";

	Animal lupik;
	lupik.print();

	Animal fluttershy("Флаттершай", "Алікорн", 20, 42);
	fluttershy.print();

}
