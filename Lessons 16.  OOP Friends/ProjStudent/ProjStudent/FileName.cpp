#include<iostream>
#include<Windows.h>
#include"Student.h"
#include<fstream>
using namespace std;

void testCinCout();
void testFile();

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	//testCinCout();
	//testFile();
	//хочу записувати список студентів у файл npr511.txt

	const char* fileName = "npr511.txt";
	//ofstream outFile(fileName);
	//Student melnyk("Мельник Матвій", "096 654 87 34", 13);
	//Student lichyk("Ліщук Давид", "096 425 55 52", 24);
	//outFile << melnyk << lichyk;
	//outFile.close();
	
	Student temp;
	ifstream myReader(fileName);
	//myReader >> temp;
	//cout << temp << '\n';
	//myReader >> temp;
	//cout << temp << '\n';
	while (!myReader.eof()) // eof - це кінець файлу
	{
		Student item;
		myReader >> item;
		if (myReader.eof()) // якщо кінця файлую далі не рухається
			break; // якщо кінець файлу
		cout << item << '\n';
	}

}

void testCinCout()
{

	cout << "===Дружні методи===\n";
	Student ivan; // викликажмо дефолтний конструктор по замовченню

	//ivan.print();
	cout << "Приклад по замовчуванню\n";
	cout << ivan << "\n";

	//конструктор з параметрами
	Student semen("Максим Федорович", "+380966789592", 23);
	cout << "конструктор з параметрами\n";
	cout << semen << "\n";

	Student maxim(semen); // викликаємо конструктор копіювання
	cout << "конструктор копіювання:\n";
	cout << maxim << "\n";

	Student vulkan;
	cout << "Вкажіть дані про студента Вулкан:\n";
	cin >> vulkan; // istream буде вводити дані про student

	cout << "Інформація, яку ви ввели: \n";
	cout << vulkan << "\n"; // ostream - буде виводити дані
}

void testFile()
{
	ofstream outFile("students.txt");
	// працює так само як cout але у файл
	outFile << "Класна погода";
	outFile.close();
	// працює так само як cin але у файл
	ifstream readFile("students.txt");
	char ch[100];
	readFile.getline(ch, 100, '\n');
	cout << "File DATA --" << ch << endl;
	readFile.close();
}