#include<iostream>
#include<Windows.h>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	srand(time(0));

	int scourUser;
	int scourPC;
	int sum;

	for (int i = 1; i < 4;i++)
	{
		int d1 = rand() % 6 + 1;
		int d2 = rand() % 6 + 1;

		int d3 = rand() % 6 + 1;
		int d4 = rand() % 6 + 1;

		cout << "                         / РАУНД /                            \n"
			<< "Користувач('_')              " << i << "             Комап'ютер(%_%)\n"
			<< " результат 2 кубиків: " << d1 << " " << d2 << "          результат 2 кубиків: " << d3 << " " << d4 << "\n\n";
		scourUser = d1 + d1;
		scourPC = d3 + d4;
	}
	if (scourUser > scourPC)
		cout << "Переможець Користувач!!!\n	Рахунок Користувача: " << scourUser << "\n	Рахунок ПК: " << scourPC << endl;
	else if(scourPC > scourUser)
		cout << "Переможець Комп'ютер!!!\n	Рахунок Користувача: " << scourUser << "\n	Рахунок ПК: " << scourPC << endl;
	else if (scourPC = scourUser)
		cout << "Нічія!!!\n	Рахунок Користувача: " << scourUser << "\n	Рахунок ПК: " << scourPC << endl;
	return 0;
}