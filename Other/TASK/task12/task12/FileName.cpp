#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	const int N = 5;
	const int M = 7;

	int arrA[N];
	int arrB[M];
	int arrAB[N + M];

	for (int i = 0; i < N; i++) {
		cin >> arrA[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> arrB[i];
	}

	int* ptrA = arrA;
	int* ptrB = arrB;
	int* ptrAB = arrAB;

	int* endA = arrA + N;
	int* endB = arrB + M;

	// 1. Поки обидва масиви мають елементи
	while (ptrA < endA && ptrB < endB)
	{
		if (*ptrA < *ptrB) {
			*ptrAB = *ptrA;
			ptrA++; // Зсуваємо ТІЛЬКИ A
		}
		else {
			*ptrAB = *ptrB;
			ptrB++; // Зсуваємо ТІЛЬКИ B
		}
		ptrAB++; // Результатуючий зсуваємо завжди
	}

	// 2. Докопійовуємо залишки з A (якщо є)
	while (ptrA < endA) {
		*ptrAB = *ptrA;
		ptrA++;
		ptrAB++;
	}

	// 3. Докопійовуємо залишки з B (якщо є)
	while (ptrB < endB) {
		*ptrAB = *ptrB;
		ptrB++;
		ptrAB++;
	}

	// Вивід результату
	cout << "Об'єднаний масив: ";
	ptrAB = arrAB;
	for (int i = 0; i < N + M; i++) {
		cout << *ptrAB << " ";
		ptrAB++;
	}



	return 0;
}