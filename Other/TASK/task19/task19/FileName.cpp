#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

struct Node
{
	int data; // значення
	Node* left; // вказівние на ліве піддерево
	Node* right; // вказівник на праве піддерево

	Node(int val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree
{
private:
	Node* root; // Корінь дерева

	// Приватний рекурсивний метод для додавання
	Node* insertRecursive(Node* current, int val)
	{
		if (current == nullptr)
		{
			return new Node(val); // знайшли порожнє місце, створюємо вузол
		}

		if (val < current->data)
		{
			current->left = insertRecursive(current->left, val); // йдемо ліворуч
		}

		else if (val > current->data)
		{
			current->right = insertRecursive(current->right, val); // йдемо праворуч
		}

		return current;
	}

	// Рекурсивний вивід едементів від меншого до більшого
	void printInOrder(Node* current)
	{
		if (current == nullptr) return;

		printInOrder(current->left); // спочатку лівепіддерево
		cout << current->data << " "; // сам вузол
		printInOrder(current->right); // праве піддерево
	}

	// Рекрусивний декструктор
	void clear(Node* current)
	{
		if (current == nullptr) return;
		clear(current->left);
		clear(current->right);
		delete current; // видаляємо вузоол лише рісля того як видалили його дітей
	}
public:
	BinaryTree()
	{
		root = nullptr;
	}

	~BinaryTree()
	{
		clear(root); // видаляємо всі вузли з купі без memory leak
	}

	void insert(int val)
	{
		root = insertRecursive(root, val);
	}

	void show()
	{
		printInOrder(root);
		cout << '\n';
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);



	return 0;
}