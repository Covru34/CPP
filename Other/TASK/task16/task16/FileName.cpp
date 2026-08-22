#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

class Car
{
private:
	string model;
	int horsePower;
	int price;
public:
	Car(string model, int horsePower, int price) // Конструктор з параметрами
	{
		this->model = model;
		this->horsePower = horsePower;
		this->price = price;
	}

	Car() // Конструктор за замовчуванням
	{
		model = "Empty";
		horsePower = 0;
		price = 0;
	}

	string getModel()
	{
		return model;
	}

	int getHP() const
	{
		return horsePower;
	}

	int getPrice() const
	{
		return price;
	}

	int tune(int hp)
	{
		return horsePower += hp;
	}

	// Перевантаження оператора порівняння
	bool operator>(const Car& other) const
	{
		return this->getHP() > other.getHP();
	}

	// Перевантаження оператора виводу
	friend ostream& operator<<(ostream& os, const Car& car)
	{
		os << "Авто: " << car.model
			<< " | Потужність: " << car.horsePower
			<< " к.с. | Ціна: " << car.price
			<< " $\n";
		return os;
	}
};

class Drive
{
private:
	Car& car;
	string driverName;
public:
	Drive(Car& c, string dn) : car(c), driverName(dn) {};

	void start()
	{
		cout << "Стан автомобіля на початку заїзду:\n" << car;
		car.tune(20);
		cout << "Стан автомобіля після заїзду:\n" << car;
	}

};

class Dealership
{
private:
	Car cars[5];
	int count = 0;
public:
	

	void addCar(const Car& car)
	{
		if (count < 5)
		{
			cars[count] = car;
			count++;
		}
		else {
			cout << "Салон заповнений!\n";
		}
	}

	void showAll()
	{
		for (int i = 0;i < count;i++)
		{
			cout << i + 1 << ". " << cars[i];
		}
	}

	void findCar(string model)
	{
		for (int i = 0;i < count; i++)
		{
			if (cars[i].getModel() == model)
			{
				cout << "Знайдено: " << cars[i];
				return;
			}
		}
		cout << "Такого автомобіля не має\n";
	}

	void removeCar(string model)
	{
		for (int i = 0; i < count; i++)
		{
			if (cars[i].getModel() == model)
			{
				for (int j = i;j < count - 1;j++)
				{
					cars[j] = cars[j + 1];
				}
				count--;
				cout << "Автомобіль " << model << " видалено\n";
				return;
			}
		}
		cout << "Автомобіль " << model << " не знайдено\n";
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	
	Car BMW("BMW M3", 473, 78400);
	cout << BMW;
	Car Audi("Audi A4", 150, 44100);
	cout << Audi;

	if (BMW > Audi)
	{
		cout << BMW.getModel() << " краще за " << Audi.getModel() << '\n';
	}
	else {
		cout << Audi.getModel() << " краще за " << BMW.getModel() << '\n';
	}

	Drive bmw(BMW, "Володимер");
	bmw.start();

	Dealership mySalon;
	mySalon.addCar(BMW);
	mySalon.addCar(Audi);
	mySalon.showAll();
	mySalon.findCar("BMW M3");
	mySalon.removeCar("Audi A4");
	mySalon.showAll();

	return 0;
}