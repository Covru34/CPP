#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

void printCard(int value, char suit);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

    int value;
    char suit;
    

    cout << "Введіть значення карти (2-14): ";
    cin >> value;

    cout << "Введіть масть (H - черви, D - бубни, C - трефи, S - піки): ";
    cin >> suit;

    printCard(value, suit);

	return 0;
}

void printCard(int value, char suit)
{
    string val;
    string suitName;

    // значення карти
    switch (value)
    {
    case 11: val = "Валет"; break;
    case 12: val = "Дама"; break;
    case 13: val = "Король"; break;
    case 14: val = "Туз"; break;
    default: val = to_string(value);
    }

    // масть
    switch (suit)
    {
    case 'H': suitName = "Черви"; break;
    case 'D': suitName = "Бубни"; break;
    case 'C': suitName = "Трефи"; break;
    case 'S': suitName = "Піки"; break;
    }

    cout << "Ваша карта: " << val << " " << suitName << endl;
}