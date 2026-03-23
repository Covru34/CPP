#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int number;
	cout << "Введіть ціле шестизначне число: \n";
	cin >> number;

	if (number < 100000 || number > 999999)
	{
		cout << "Ви ввели не шестизначне число\n";
	}

    int digit1 = number / 100000;          
    int digit2 = (number / 10000) % 10;    
    int digit3 = (number / 1000) % 10;     
    int digit4 = (number / 100) % 10;      
    int digit5 = (number / 10) % 10;       
    int digit6 = number % 10;              

    int sum1 = digit1 + digit2 + digit3;   
    int sum2 = digit4 + digit5 + digit6;   

   
    if (sum1 == sum2) {
        cout << "Число щасливе!" << endl;
    }
    else {
        cout << "Число нещасливе." << endl;
    }

	return 0;
}