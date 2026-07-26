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

	virtual void takeDamage(int damage) = 0;

};

class Wizard : public Hero {
private:
	int mana;
public:
	Wizard(string wizardName, int wizardHealth, int wizardMana)
		: Hero(wizardName, wizardHealth) { // виклкиємо конструтор класа Hero так як не має потреби створювати змінні в name і health щей в цьому класі
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

class Warrior : public Hero {
private:
	int stamina;
public:
	Warrior(string warriorName, int warriorHealth, int warriorStamina)
		: Hero(warriorName, warriorHealth) {
		stamina = warriorStamina;
	}

	void punch() {
		if (stamina >= 50) {
			stamina -= 50;
			cout << getName() << " наносить удар мечом. (Стаміна: " << stamina << ")\n";
		}
		else {
			cout << getName() << " втомився\n";
		}
	} 
	
	void takeDamage(int damage) override {
		if (stamina >= 10) {
			stamina -= 10;
			damage = damage - 5;
			if (damage < 0) damage = 0;
			health -= damage;
			if (health < 0) health = 0;
			cout << name << " отримав " << damage << " шкоди. Залишклося HP: " << health << "\n";
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

	Wizard arsen("Арсен", 90, 20);
	Archer mykola("Міколя", 100, 5);
	Warrior lupik("Ярик", 120, 160);

	Hero* team[3];
	team[0] = &arsen;
	team[1] = &mykola;
	team[2] = &lupik;

	cout << "=== ПАБЛІН НАНОСИТЬ УДАР БАНАНОМ ПО ОБЛАСТІ (ПО 30 ШКОДИ ВСІМ) ===\n\n";

	for (int i = 0; i < 3; i++)
	{
		team[i]->takeDamage(30);
		cout << "-------------------------------\n";
	}

	return 0;
}