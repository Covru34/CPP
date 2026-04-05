#include<iostream>  // бібліотека для вводу/виводу

int main()  // головна функція програми
{//приклад 1, с. 29
	using namespace std;  // дозволяє використовувати cout, cin без std::

	cout << "What's up, Doc! \n ";
	// виводить текст на екран
	// \n — перехід на новий рядок

	//return 0;
	// завершення програми (закоментовано, тому не працює)

	// приклад 2, с.50

	//#include<iostream>
	//int main()
	// закоментований код іншої програми (не виконується)

	using namespace std;
	// повторне підключення простору імен (необов’язково, але не заважає)

	cout << " Come up and С++ me some time.";
	// вивід тексту

	cout << endl;
	// перехід на новий рядок

	
	cout << "Уои won't regret it  " << endl;
	// вивід ще одного рядка тексту

	// приклад 3, с. 67

	//#include<iostream>
	//int main()
	// ще один закоментований фрагмент програми

	using namespace std;
	// ще один повтор using namespace std

	int carrots;
	// оголошення змінної для кількості морквин

	cout << "How many carrots do you have ?" << endl;
	// запит до користувача

	cin >> carrots;
	// введення числа з клавіатури у змінну carrots

	
	cout << "Here are two more.";
	// повідомлення користувачу

	carrots = carrots + 2;
	// додаємо 2 до введеного значення

	cout << "Now you have " << carrots << " carrots." << endl;
	// виводимо результат (оновлену кількість)

	return 0;
	// завершення програми
}