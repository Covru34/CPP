#include<iostream>
#include<Windows.h>
#include<thread>

using namespace std;



int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	char a;
	int way;
	int time;

	cout << "Введіть символ якій би ви хотіли бачити в якості лінії: \n->_ ";
	cin >> a;
	cout << "Виберіть напрямок для своєї ліній: \n 1.Горизонтально \n 2.Вертикально \n->_ ";
	cin >> way;
	cout << "Виберіть швидкість для появлення лінії: \n 1.Швидко \n 2.Нормально \n 3.Повільно \n->_ ";
	cin >> time;
	
	if (time == 1)
			time = 10;
		else if (time == 2)
			time = 100;
		else if (time == 3)
			time = 200;

	if (way == 1)
	{
		for (int i = 0; i < 25;i++)
		{
			cout << a;
			this_thread::sleep_for(chrono::milliseconds(time));
		}
	}
	if (way == 2)
	{
		for (int i = 0;i < 25;i++)
		{
			cout << a << endl;
			this_thread::sleep_for(chrono::milliseconds(time));
		}
	}

	return 0;
}

