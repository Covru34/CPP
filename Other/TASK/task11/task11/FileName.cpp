#include<iostream>
#include<Windows.h>
using namespace std;

int main() 
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[5];
	cout << "Введіть масив із 5 цілих чисел: \n";
	for (int i = 0; i < 5;i++)
	{
		cout << i + 1 << ". ";
		cin >> arr[i];
	}

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << i + 1 << ". " << arr[i] << "\n";
	//}

	int* ptr = arr;
	int* min_ptr = arr;
	int* max_ptr = arr;

	for (int i = 0;i < 5;i++)
	{
		if (*ptr > *max_ptr)
			max_ptr = ptr;
		if (*ptr < *min_ptr)
			min_ptr = ptr;
		ptr++;
	}

	int* start;
	int* end;
	if (min_ptr < max_ptr) {
		start = min_ptr;
		end = max_ptr;
	}
	else {
		start = max_ptr;
		end = min_ptr;
	}
	int count = end - start - 1;

	if (count > 0)
	{
		int reversArr[5];
		int* rptr = reversArr;

		ptr = end - 1;

		while (ptr > start) {
			*rptr = *ptr;
			rptr++;
			ptr--;
		}
	

		cout << "\nЕлементи між ними у зворотному порядку:\n";
		for (int i = 0; i < count; i++) {
			cout << reversArr[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << "\nМіж мінімумом та максимумом немає елементів.\n";
	}

	return 0;
}
