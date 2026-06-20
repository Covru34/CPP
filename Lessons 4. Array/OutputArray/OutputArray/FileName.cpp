#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << "Привіт! Будемо вводити масив з клавіатури :)\n";

    const int n = 5; //кількість елементів масиву
    int peopleAge[n]; // створили масив на 5 елементів(n=5)

    cout << "---Вкажіть значення елементів масиву----";
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> peopleAge[i];
    }

    cout << "Значеня в масиву: ";
    for (int i = 0; i < n; i++)
        cout << peopleAge[i] << "\t";
    cout << "\n";
    return 0;
}
