#include<iostream>
#include<Windows.h>
#include<cmath>
using namespace std;

int binaryToDecimal(long long binary);

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    long long binary;
    cout << "Введіть двійкове число: ";
    cin >> binary;

    int result = binaryToDecimal(binary);

    cout << "Десяткове число: " << result << endl;

    return 0;
}

int binaryToDecimal(long long binary)
{
    int decimal = 0;
    int step = 0;   // ступінь двійки (2^0, 2^1, 2^2 ...)

    while (binary != 0)
    {
        int digit = binary % 10;          // беремо останню цифру (0 або 1)
        decimal += digit * pow(2, step); // множимо на відповідний ступінь двійки
        binary /= 10;                   // відкидаємо останню цифру
        step++;                           // переходимо до наступного розряду
    }

    return decimal;
}