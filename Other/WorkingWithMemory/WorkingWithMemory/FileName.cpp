#include<iostream>
#include<Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
    
    int value = 42; // змінна стеку
    int* ptr = &value; // вказівник зберігає адресу value

    cout << "Value: " << *ptr << "\n"; // отримали доступ до значення зімнної value за її адресою

    // nullptr - безпечний нульовий вказівник 
    int* nullPtr = nullptr;

    return 0;
}