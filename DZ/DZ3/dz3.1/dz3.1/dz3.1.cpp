#include <iostream>
#include <Windows.h>

int main() {
    using namespace std;
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int time;
    int from, to; 

    
    int kiviToKivi = 1;
    int kiviToVodafon = 3;
    int vodafonToVodafon = 2;

    cout << "Введіть тривалість розмови (хв): ";
    cin >> time;

    cout << "Виберіть оператора з якого дзвоните:\n";
    cout << "1 - Київстар\n2 - Водафон\n";
    cin >> from;

    cout << "Виберіть до якого оператора дзвоните:\n";
    cout << "1 - Київстар\n2 - Водафон\n";
    cin >> to;

    int cost = 0;

    if (from == 1 && to == 1) {
        cost = time * kiviToKivi;
    }
    else if (from == 1 && to == 2) {
        cost = time * kiviToVodafon;
    }
    else if (from == 2 && to == 2) {
        cost = time * vodafonToVodafon;
    }
    else if (from == 2 && to == 1) {
        cost = time * kiviToVodafon; 
    }
    else {
        cout << "Ви ввели щось не те";
        return 0;
    }

    cout << "Вартість дзвінка: " << cost << " грн";
    return 0;
}