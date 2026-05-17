#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	cout << "Робота з файлами\n";
	//є 2 режима роботи з файлами
	//1 - запис у файл - out
	//2 - читання фалу - in
	//для запису й файл є спеціальний тип
	//ofstream - для запису у файл
	//ifstream - читання з файлу
	//працює аеалогічно як cout & cin
	//покаєемо етапи роботи з файлами
	//1 - створюємо потік для запису файлу
	ofstream fout("my.txt"); //працюємо із файлом my.txt
	fout << "Сьогодні хороша погода\n";
	fout << "Мабуть піду купатися\n";
	fout.close();
}