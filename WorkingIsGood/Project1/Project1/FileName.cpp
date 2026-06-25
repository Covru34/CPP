#include<iostream>
#include<string>
#include<Windows.h>
#include<ctime>
using namespace std;

class Hero { // шаблоний клас
protected:
	string name;
	int health;
public:
	Hero(string heroName, int heroHealth) { // ця функція називається конструктором, конструктор це работнік якій створює отдельний hero та health для кожного героя та зосовує це значення в нього
		name = heroName;
		health = heroHealth;
	}

	string getName() {
		return name;
	}

	virtual void takeDamage(int damage) {
		health -= damage;
		if (health < 0) health = 0;
		cout << name << " отримав " << damage << " шкоди. Залишклося HP: " << health << "\n";
	}

};

class Wizard : public Hero {
private:
	int mana;
public:
	Wizard(string wizardName, int wizardHealth, int wizardMana)
		: Hero(wizardName, wizardHealth) { // виклкиємо конструтор класа Hero так як не має потреби створювати змінні в name і health щей в цбоиу класі
		mana = wizardMana; // додаємо нову змінну для конструктора мага
	}

	void castSpell() {
		if (mana >= 10) {
			mana -= 10;
			cout << getName() << " чаклує вогняну кулю (Мана: " << mana << ")\n";
		}
		else {
			cout << getName() << " не хватає мани!\n";
		}
	}

	void takeDamage(int damage) override {
		if (mana >= 5) {
			mana -= 5;
			damage = damage / 2;
			health -= damage;
			if (health < 0) health = 0;
			cout << "[МАГІЧНИЙ ЩИТ] (Мана: " << mana << ")\n";
			cout << name << " отримав " << damage << " шкоди. Залишклося HP: " << health << "\n";
		}
		else {
			cout << getName() << " не хватає мани для щита!\n";
			health -= damage;
			if (health < 0) health = 0;
			cout << name << " отримав " << damage << " шкоди. Залишклося HP: " << health << "\n";
		}
	}
};

class Archer : public Hero {
private:
	int arrows;
public:
	Archer(string archerName, int archerHealth, int archerArrows)
		: Hero(archerName, archerHealth) {
		arrows = archerArrows;
	}

	void shootArrow() {
		if (arrows >= 1) {
			arrows -= 1;
			cout << getName() << " вистрілює з лука(Стріли: " << arrows << ")\n";
		}
		else {
			cout << getName() << " не хватає стріл!\n";
		}
	}

	void takeDamage(int damage) override {
		if (rand() % 10 < 3) {
			cout << getName() << "  ухилився від удара та отримав 0 шкоди. (HP: " << health << ")\n";
		}
		else {
			health -= damage;
			if (health < 0) health = 0;
			cout << name << " отримав " << damage << " шкоди. Залишклося HP: " << health << "\n";
		}
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	srand(time(0));

	Hero lupik("Чмошнік люпік", 50);
	lupik.takeDamage(30);

	cout << "------------------------\n";

	Wizard arsen("Арсен", 90, 20);
	arsen.castSpell();
	arsen.takeDamage(15);
	arsen.takeDamage(10);
	arsen.takeDamage(5);
	

	cout << "------------------------\n";

	Archer pablin("Паблін", 100, 3);
	pablin.shootArrow();
	pablin.takeDamage(10);
	pablin.takeDamage(10);
	pablin.takeDamage(10);
	pablin.shootArrow();
	pablin.takeDamage(15);
	pablin.shootArrow();
	pablin.takeDamage(30);
	pablin.shootArrow();

	return 0;

}