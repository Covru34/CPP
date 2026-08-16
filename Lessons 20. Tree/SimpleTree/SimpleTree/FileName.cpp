#include<iostream>
#include<Windows.h>
using namespace std;

//Структура С++ - для зберігання власних типів даних
//У структурі, як в класі ми можемо об'єднувати декілька типів
struct Node // вузол в дереві, якій зберігає інформацію про себе
{
	int data; // дані які зберігаються в дереві
	Node* left; // ліва гілка у вузлі
	Node* right;

	// конструктор - ініціалізація при створені
	Node(int value) // передаємо значення яке зберігаємо у вузлі
	{
		data = value;
		left = nullptr;
		right = nullptr;

	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "--Працюємо з бінарними деревами--\n";
	//корінь дерева
	Node* root = new Node(10); // це голова дерева і зберігає 10
	cout << "голова дерева " << root->data << '\n';

	//Число 5 - вліво ідуть менші числа, у право більші
	root->left = new Node(5);
	cout << "Ліва гілка дерева " << root->left->data << '\n';

	root->right = new Node(15);
	cout << "Права гілка дерева " << root->right->data << '\n';

	//Що буде якщо в дерево буде заходити число 3
	root->left->left = new Node(3); // максимально іде в ліво на 3 рівень
	//Якщо додаємо 7 - 7 < 10 - іде в ліво, 7 > 5 іде в право
	root->left->right = new Node(7);


	return 0;
}