#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "Літак має летіти з пункту А, в пункт С,через пункт В. Введіть відстань (км) між пунктом А і В, і між пуктом В і С: \n";
	int AB;
	cout << "Між А і В: \n";
	cin >> AB;

	int BC;
	cout << "Між В і С: \n";
	cin >> BC;

	int weight;
	cout << "Введіть вагу літака (кг): \n";
	cin >> weight;

	double consumpition;

	if (weight <= 500)
		consumpition = 1;
	else if (weight <= 1000)
		consumpition = 4;
	else if (weight <= 1500)
		consumpition = 7;
	else if (weight <= 2000)
		consumpition = 9;
	else
	{
		cout << "Літак не долетить\n";
		return 0;
	}

	double fuelAB = AB * consumpition;
	double fuelBC = BC * consumpition;

	if (fuelAB > 300)
	{
		cout << "Літак не долетить до пункта В\n";
		return 0;
	}
	if (fuelBC > 300)
	{
		cout << "Літак не долетить до пункта С\n";
		return 0;
	}

	double fuelLeft = 300 - fuelAB;
	double need = 0;

	if (fuelLeft < fuelBC)
		need = fuelBC - fuelLeft;

	cout << "Потрібно дозаправити " << need << " л в пункті В";

	return 0;
}