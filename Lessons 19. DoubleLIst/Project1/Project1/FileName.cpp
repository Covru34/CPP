#include<iostream>
#include<Windows.h>
using namespace std;

class Doubly 
{
private:
	class Node //вузол у списку
	{
	public:
		int data; // данні які зберігає вузол
		Node* next;
		Node* prev;
	};
	Node* head; // початок списку
	// Конструктор
public:
	Doubly()
	{
		head = NULL;//на початку роботи список пустий

	}
	void Add(int data)
	{
		if (head == NULL) // додаємо на посатоку якщо список пустий
		{
			Node* myNode = new Node;
			myNode->data = data;
			myNode->prev = myNode->next = NULL;
			head = myNode; // це є перший елемент списку
		}
		else
		{
			Node* temp = head; //Починаємо із початку
			//Ідемо до останього елемента списку
			while (temp->next != NULL) //Доки ми не знаходимося у кінці
				temp = temp->next; //Переходим на наступний у списку
			Node* newNode = new Node();
			newNode->data = data; //зберігаємо дані у новий вузол
			newNode->prev = temp; //Попередній для нового буде останій елемент списку
			newNode->next = NULL; //Наступного елемента у списку немає- даний він останій
			temp->next = newNode; //Останій вузол вказну на новий вузол
		}
	}
	void ShowList()
	{
		Node* temp = head; // запам'ятавуємо початок списку
		while (temp != NULL) // Доки ми не знаходимося у кінці
		{
			cout << temp->data << "\n"; //виводимо дані ц вузіл
			temp = temp->next;//переходимо на настпуний список
		}     
	}
	void Remove(int data)
	{
		if (head == NULL)
			return;
		Node* temp = head;

		while (temp != NULL && temp->data != data)
			temp = temp->next;

		if (temp == NULL)
		{
			cout << "---Елемент, який ви хочте видалити ми не знайшли--\n";
			return;
		}
		if (temp == head)
		{
			head = head->next;
			if (head != NULL)
			{
				head->prev = NULL;
			}
			delete temp;
			return;
		}
		if (temp->next != NULL)
		{
			temp->next->prev = temp->prev;
		}
		temp->prev->next = temp->next;
		delete temp;
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "===Двохзв'язні списки===\n";

	// Перевіряжмо роботу конмтруктора і додавання у список
	Doubly myList; // конструктор
	myList.Add(12); // додавання у список
	myList.Add(42); // додавання у список
	myList.Add(3); // додавання у список
	myList.Add(123); // додавання у список
	cout << "----Набір елементів у списку----\n";
	myList.ShowList();
	myList.Remove(12);
	myList.ShowList();

	return 0;
}