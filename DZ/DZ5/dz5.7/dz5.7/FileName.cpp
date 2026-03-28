#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
    int n;
    cout << "Введіть ціле число: \n";
    cin >> n;

    int result = 0;
    int mult = 1;

    while (n > 0)
    {
        int digit = n % 10;

        if (digit != 3 && digit != 6)
        {
            result += digit * mult;
            mult *= 10;
        }

        n /= 10;
    }

    cout << result;

    return 0;
}