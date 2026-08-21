#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

class Athlete
{
private:
	string name;
	int benchPress;
	int squats;
	int deadlift;
public:
	Athlete(string name, int benchPress, int squats, int deadlift)
	{
		this->name = name;
		this->benchPress = benchPress;
		this->squats = squats;
		this->deadlift = deadlift;
	}

	void show()
	{
		cout << "Спортсмен: " << name << " | Жим: " << benchPress << " кг | Присяд: " << squats << " кг | Станова: " << deadlift << " кг\n";
	}

	void addBPweight(int weight)
	{
		benchPress += weight;
	}

	void addSweight(int weight)
	{
		squats += weight;
	}

	void addDeadlift(int weight)
	{
		deadlift += weight;
	}

	int getTotal() const
	{
		return benchPress + squats + deadlift;
	}

	string getName()
	{
		return name;
	}

	bool operator>(const Athlete& other) const
	{
		return this->getTotal() > other.getTotal();
	}

	friend ostream& operator<<(ostream& os, const Athlete& ath)
	{
		os << "Спортсмен: " << ath.name
			<< " | Жим: " << ath.benchPress
			<< " кг | Присяд: " << ath.squats
			<< " кг | Станова: " << ath.deadlift
			<< " кг\n";
		return os;
	}

};

class Workout
{
private:
	Athlete& athlete;
	string data;
public:
	Workout(Athlete& ath, string d) : athlete(ath), data(d) {};

	void startSession()
	{
		cout << "--- Тренування за " << data << " ---\nПочатковий стан спротсмена: ";
		cout << athlete;
		athlete.addBPweight(1);
		athlete.addSweight(1);
		athlete.addDeadlift(1);
		cout << "Стан спортсиена після тренування:\n";
		cout << athlete;
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Athlete Pablin("Паблін", 120, 190, 250);
	cout << Pablin;
	
	Athlete BortProvodnik("Борт", 90, 140, 170);
	cout << BortProvodnik;
	
	//if (Pablin > BortProvodnik)
	//{
	//	cout << Pablin.getName() << " сильніший за " << BortProvodnik.getName() << '\n';
	//}
	//else {
	//	cout << BortProvodnik.getName() << " сильніший за " << Pablin.getName() << '\n';
	//}

	Workout p(Pablin, "21.08.2026");
	p.startSession();

	cout << "\nПеревірка в main після тренування:\n";
	cout << Pablin;

	return 0;
}
