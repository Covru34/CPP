#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
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
	Car* cars;
	int count = 0;
	int capacity;

	void resize()
	{
		capacity *= 2;
		Car* newCars = new Car[capacity];

		for (int i = 0; i < count; i++)
		{
			newCars[i] = cars[i];
		}

		delete[] cars;
		cars = newCars;

		cout << "Салон розширено. Нова місткість: " << capacity << '\n';
	}
public:
	// створюємо масив заданого розімру
	Dealership(int cap = 5)
	{
		capacity = cap;
		cars = new Car[capacity];
	}
	// Деструктор, викликається автоматично при знищенні об'єкта
	~Dealership()
	{
		delete[] cars;
	}

	void addCar(const Car& car)
	{
		if(count == capacity)
		{
			resize();
		}
		cars[count] = car;
		count++;
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

	void saveToFile(string filename)
	{
		ofstream outFile(filename); // відкриваємо файл

		if (!outFile.is_open()) // вбудована функція в бібілотеці fstream
		{
			cout << "Помилка відкриття файлу для запису!\n";
			return;
		}

		outFile << count << '\n'; // записуємо кількість машин першим рядком

		for (int i = 0; i < count; i++)
		{
			outFile << cars[i].getModel() << '\n'
					<< cars[i].getHP() << '\n'
					<< cars[i].getPrice() << '\n';
		}

		outFile.close(); // обов'язково закриваємо файл
		cout << "Дані успішно збережені у файл " << filename << '\n';
	}

	void loadFromFile(string filename)
	{
		ifstream inFile(filename);

		if (!inFile.is_open())
		{
			cout << "Файл не знайдено!\n";
			return;
		}

		int fileCount;
		inFile >> fileCount; // зчитує кількість машин

		count = 0; // очищаємо наш поточний масив

		for (int i = 0; i < fileCount; i++)
		{
			string m;
			int hp, p;

			// зчитуємо дані з фалй в тимчасові змінні
			// ws прибирає зайві пробіли/переноси рядків перед getline
			inFile >> ws;
			getline(inFile, m); // зчитує повну назву моделі
			inFile >> hp;
			inFile >> p;

			// створюємо авто і додаємо в салон
			Car loaderCar(m, hp, p);
			addCar(loaderCar);
		}

		inFile.close();
		cout << "Дані успішно завантажені з файлу " << filename << '\n';
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	
	Car BMW("BMW_M3", 473, 78400);
	cout << BMW;
	Car Audi("Audi_A4", 150, 44100);
	cout << Audi;
	Car UA("Potyjnui_car", 420, 42000);
	cout << UA;

	//if (BMW > Audi)
	//{
	//	cout << BMW.getModel() << " краще за " << Audi.getModel() << '\n';
	//}
	//else {
	//	cout << Audi.getModel() << " краще за " << BMW.getModel() << '\n';
	//}

	//Drive bmw(BMW, "Володимер");
	//bmw.start();

	//Dealership mySalon;
	//mySalon.addCar(BMW);
	//mySalon.addCar(Audi);
	//mySalon.showAll();
	//mySalon.findCar("BMW M3");
	//mySalon.removeCar("Audi A4");
	//mySalon.showAll();

	//mySalon.saveToFile("cars.txt");
	//Dealership newSalon;
	//newSalon.loadFromFile("cars.txt");
	//newSalon.showAll();

	Dealership secondSalon(2);
	secondSalon.addCar(BMW);
	secondSalon.addCar(Audi);
	secondSalon.addCar(UA);
	secondSalon.showAll();

	return 0;
}