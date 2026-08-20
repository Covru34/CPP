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
public:
	Athlete(string name, int benchPress, int squats)
	{
		this->name = name;
		this->benchPress = benchPress;
		this->squats = squats;
	}

	void show()
	{
		cout << "Спортсмен: " << name << " | Жим: " << benchPress << " кг | Присяд: " << squats << " кг\n";
	}

	void addBPweight(int weight)
	{
		benchPress += weight;
	}

	void addSweight(int weight)
	{
		squats += weight;
	}


};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Athlete Pablin("Паблін", 120, 190);
	Pablin.show();
	Pablin.addBPweight(10);
	Pablin.show();

	Athlete BortProvodnik("Борт", 90, 140);
	BortProvodnik.show();
	BortProvodnik.addSweight(10);
	BortProvodnik.show();

	return 0;
}
