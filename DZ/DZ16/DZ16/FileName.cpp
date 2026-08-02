#include<iostream>
#include<Windows.h>
using namespace std;

class Hero {
private:
	string name;
	int health;
public:
	Hero(string heroName, int heroHealth) {
		name = heroName;
		health = heroHealth;
	}

	int getHealth() {
		return health;
	}

	string getName() {
		return name;
	}

	int takeDamage(int damage) {
		health -= damage;
		if (health < 0)
			health = 0;
		return health;
	}

	
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Hero lupik("Люпік", 100);

	lupik.takeDamage(120);

	return 0;
}