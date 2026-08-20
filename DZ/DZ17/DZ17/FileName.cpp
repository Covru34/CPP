#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Car
{
private:
	string carNumber; // Номер автомобіля 
	string* fines;    // Динамічний масив штрафів
	int finesCount;   // Кількість штрафів

public:
	//  Конструктор за замовчуванням
	Car(string number = "")
	{
		carNumber = number;
		finesCount = 0;
		fines = nullptr;
	}

	// Деструктор (очищення пам'яті)
	~Car()
	{
		delete[] fines;
	}

	// Конструктор копіювання (глибока копія)
	Car(const Car& other)
	{
		carNumber = other.carNumber;
		finesCount = other.finesCount;

		if (other.finesCount > 0)
		{
			fines = new string[finesCount];
			for (int i = 0; i < finesCount; i++)
			{
				fines[i] = other.fines[i];
			}
		}
		else
		{
			fines = nullptr;
		}
	}

	// Оператор присвоєння (глибока копія)
	Car& operator=(const Car& other)
	{
		if (this == &other)
			return *this; // Захист від car = car

		delete[] fines; // Звільняємо старі дані

		carNumber = other.carNumber;
		finesCount = other.finesCount;

		if (other.finesCount > 0)
		{
			fines = new string[finesCount];
			for (int i = 0; i < finesCount; i++)
			{
				fines[i] = other.fines[i];
			}
		}
		else
		{
			fines = nullptr;
		}

		return *this;
	}

	// Метод додавання штрафу
	void addFine(string fine)
	{
		string* temp = new string[finesCount + 1];

		for (int i = 0; i < finesCount; i++)
		{
			temp[i] = fines[i];
		}

		temp[finesCount] = fine;

		delete[] fines;
		fines = temp;
		finesCount++;
	}

	// Перевантаження оператора виводу
	friend ostream& operator<<(ostream& os, const Car& car)
	{
		os << "Авто: [" << car.carNumber << "] | Штрафи: ";
		if (car.finesCount == 0)
		{
			os << "немає";
		}
		else
		{
			for (int i = 0; i < car.finesCount; i++)
			{
				os << car.fines[i] << (i + 1 < car.finesCount ? ", " : "");
			}
		}
		return os;
	}

	// Оператори порівняння для дерева
	bool operator<(const Car& other) const
	{
		return carNumber < other.carNumber;
	}

	bool operator>(const Car& other) const
	{
		return carNumber > other.carNumber;
	}

	bool operator==(const Car& other) const
	{
		return carNumber == other.carNumber;
	}
};


class Node
{
private:
	Car data;
	Node* left;
	Node* right;

public:
	Node(const Car& data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}

	friend class BinarySearchTree;
};


class BinarySearchTree
{
private:
	Node* root;

	Node* insert(Node* node, const Car& value)
	{
		if (node == nullptr)
			return new Node(value);

		if (value < node->data)
			node->left = insert(node->left, value);
		else if (value > node->data)
			node->right = insert(node->right, value);

		return node;
	}

	void view(Node* node)
	{
		if (node == nullptr)
			return;

		view(node->left);
		cout << node->data << '\n';
		view(node->right);
	}

	bool search(Node* node, const Car& value)
	{
		if (node == nullptr)
			return false;
		if (node->data == value)
			return true;

		if (value < node->data)
			return search(node->left, value);
		return search(node->right, value);
	}
	
	void printRange(Node* node, const Car& from, const Car& to)
	{
		if (node == nullptr)
			return;

		if (node->data > from)
			printRange(node->left, from, to);

		if (!(node->data < from) && !(node->data > to))
			cout << node->data << '\n';

		if (node->data < to)
			printRange(node->right, from, to);
	}

public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	void Add(const Car& value)
	{
		root = this->insert(root, value);
	}

	void show()
	{
		view(root);
		cout << '\n';
	}

	bool Find(const Car& value)
	{
		return search(root, value);
	}

	void showRange(string startNumber, string endNumber)
	{
		Car startCar(startNumber);
		Car endCar(endNumber);

		cout << "--- Звіт та діапазон [" << startNumber << " ... " << endNumber << "] ---\n";
		printRange(root, startCar, endCar);
		cout << '\n';
	}
};


int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Car car1("BC1111AA");
	car1.addFine("Перевищення швидкості");
	car1.addFine("Ремінь");

	Car car2("AA0001BP");

	Car car3("BX5555EX");
	car3.addFine("Парковка");

	Car car4("AB1234BC");
	car4.addFine("Червоне світло");

	BinarySearchTree database;
	database.Add(car1);
	database.Add(car2);
	database.Add(car3);
	database.Add(car4);

	cout << "База даних авто (відсортована за номером):\n";
	database.show();

	cout << "--- Перевірка пошуку ---\n";
	Car searchTarget1("BC1111AA");
	Car searchTarget2("XX9999XX");

	cout << "Пошук BC1111AA: " << (database.Find(searchTarget1) ? "Знайдено" : "Не знайдено") << '\n';
	cout << "Пошук XX9999XX: " << (database.Find(searchTarget2) ? "Знайдено" : "Не знайдено") << '\n';

	database.showRange("AA0000AA", "BC9999ZZ");

	return 0;
}