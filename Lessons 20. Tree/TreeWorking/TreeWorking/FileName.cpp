#include<iostream>
#include<Windows.h>
using namespace std;

class Node
{
private:
	int data;
	Node* left;
	Node* right;
public:
	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr; // знизу гілок не має
	}
	// щоб  BinarySearchTree мав доступ до приватоного блоку Node 
	friend class BinarySearchTree; // Тобто у нас BinarySearchTree має доступ

};

//Будуємо кдас який куруває деревами
class BinarySearchTree
{
private:
	Node* root; // знає про корінь дерева
	// метод для додавання нового елемента в дерево
	Node* insert(Node* node, int value)
	{
		// якщо вузол порожній - nullptr
		if (node == nullptr)
			return new Node(value);
		// якщо в дереві не пустий й вущол - тобто root ми маємо знайти де має бути вузол
		if (value < node->data) // ідемо в ліво
			node->left = insert(node->left, value);

		else if (value > node->data) // має піти до правого краю
			node->right = insert(node->right, value);

		return node; // повертаємо вказівник на поточний вузол
		
	}
	// щоб відобразити елемент дерева по ньоиу потрібно пройти
	// прохід по дереву виконується у сортованому вигляді
	// за допоиогою рекурсії - виклик метода сам себе і повернення нахд
	void view(Node* node)
		{
		if (node == nullptr) // інакше буде зациклення 
			return; // дійшли до кінця дерева, більше елементів не має
		// якщо дерево з більшого до меншого тоді ідемо з початку з ліва
		// а потім на право
		// тут іде виклик метода сам себе - називається рекурсія
		view(node->left); // звертаюся до лівого вузла і викликаю його
		cout << node->data << '\t';
		view(node->right); // доки дерево не обійдемо до nullptr 

		}
	void viewReverse(Node* node) // взворотній порядок виводу - від більшого до меншого
		{
		if (node == nullptr) // інакше буде зациклення 
			return; // дійшли до кінця дерева, більше елементів не має
		// якщо дерево з більшого до меншого тоді ідемо з початку з ліва
		// а потім на право
		// тут іде виклик метода сам себе - називається рекурсія
		viewReverse(node->right); // звертаюся до лівого вузла і викликаю його
		cout << node->data << '\t';
		viewReverse(node->left); // доки дерево не обійдемо до nullptr 

		}
	bool search(Node* node, int value) // node - поточний вузол, value - що шукаємо
	{
		if (node == nullptr) // обійшлм дерево і нічого не знайшли
			return false;
		if (node->data == value)
			return true; // знайшли елемент, який шукали
		// відносно того елемента, що шукаємо або в ліво або в право
		if (value < node->data)
			return search(node->left, value); // ідемо в право, якщо відносно поточно більше
		return search(node->right, value);

	}

public:
	// на початку роботи, дерево буде пусте
	BinarySearchTree()
	{
		root = nullptr; // дерево пусте
	}

	void Add(int value)
	{
		root = this->insert(root, value);
	}

	void show()
	{
		view(root); //за допоиогою рекурсії обходимо дерево і вивиодимо на екран
		cout << '\n';

	}
	void showReverse()
	{
		viewReverse(root); // з права на ліво робимо обхід дерева
		cout << '\n';

	}
	bool Find(int value)
	{
		return search(root, value);
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "--OOP і бінарні дерева--\n";
	BinarySearchTree myTree;
	myTree.Add(10); // якщо додаємо 1 елемент, він є root
	myTree.Add(5); // має піти в ліву гілку і там зберегтися
	myTree.Add(15); // має піти в праву гілку і там зберегтися
	myTree.Add(20); 
	myTree.Add(17); 
	myTree.Add(8); 
	myTree.Add(3); 

	myTree.show(); // виводимо дерево на еркна
	myTree.showReverse(); // від більшого до меншого

	cout << "Пошук числа 8 - " << myTree.Find(8) << '\n';
	cout << "Пошук числа 123 - " << myTree.Find(123) << '\n';

	return 0;
}