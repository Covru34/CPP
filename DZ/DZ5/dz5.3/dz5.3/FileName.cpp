#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Введіть a: ";
    cin >> a;

    if (a < 1 || a > 20)
    {
        cout << "Помилка!";
        return 0;
    }

    long long product = 1;

    for (int i = a; i <= 20; i++)
    {
        product *= i;
    }