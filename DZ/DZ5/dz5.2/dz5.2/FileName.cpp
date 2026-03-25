#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

    int sum = 0;

    for (int i = 1; i <= 1000; i++)
    {
        sum += i;
    }

    double avg = sum / 1000.0;

    cout << "Середнє: " << avg;

    return 0;
}