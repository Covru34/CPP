#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

class Item 
{
private:
	// назва, рідкість та вага
	string name;
	string rarity;
	int weight; 
public:
	// Конструктор за замовчуванням та з параметрами
	Item(string name, string rarity, int weight)
	{
		this->name = name;
		this->rarity = rarity;
		this->weight = weight;
	}

	Item()
	{
		name = "Empty";
		rarity = "Empty";
		weight = 0;
	}
	//гетери
	string getName()
	{
		return name;
	}

	string getRariry()
	{
		return rarity;
	}

	int getWeight() const
	{
		return weight;
	}

	friend ostream& operator<<(ostream& os, const Item& it)
	{
		os << "Предмета: " << it.name
			<< " | Рідкість: " << it.rarity
			<< " | Вага: " << it.weight
			<< '\n';
		return os;
	}
};

class Inventory
{
private:
	Item* items;
	int count;
	int capacity;

	void resize()
	{
		capacity *= 2;
		Item* newItems = new Item[capacity];

		for (int i = 0; i < count; i++)
		{
			newItems[i] = items[i];
		}

		delete[] items;
		items = newItems;

		cout << "Інвентарь розширено. Нова місткість: " << capacity << '\n';
	}
public:
	Inventory(int cap = 2)
	{
		count = 0;
		capacity = cap;
		items = new Item[capacity];
	}

	~Inventory()
	{
		delete[] items;
	}

	void addItem(const Item& item)
	{
		if (count == capacity)
		{
			resize();
		}
		items[count] = item;
		count++;
	}

	void showInventory()
	{
		for (int i = 0; i < count;i++)
		{
			cout << i + 1 << ". " << items[i];
		}
	}

	void dropItem(string name)
	{
		for (int i = 0; i < count; i++)
		{
			if (items[i].getName() == name)
			{
				for (int j = i;j < count - 1; j++)
				{
					items[j] = items[j + 1];
				}
				count--;
				cout << "Предмет " << name << " викінуто\n";
				return;
			}
		}
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Item sword("Iron Sword", "Common", 5);
	Item potion("Health Potion", "Common", 1);
	Item shield("Dragon Shield", "Legendary", 12);

	Inventory inv;
	inv.addItem(sword);
	inv.addItem(potion);
	inv.addItem(shield); // Тут має спрацювати resize()

	inv.showInventory();
	inv.dropItem("Health Potion");
	inv.showInventory();

	return 0;
}