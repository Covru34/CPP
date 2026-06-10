#include<iostream>
int main()
{
	using namespace std;
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts value = " << donuts;
	cout << " and donuts address = " << &donuts << endl;

	cout << "cups value = " << cups;
	cout << " and cups address = " << &cups << endl;
	// у цьому прикладі ми поживились значення донатсів та чашок і їхню адресу

	int updates = 6;
	int* p_updates;
	p_updates = &updates;

	cout << "Values: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;

	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "Now updates = " << updates << endl;
	// робота з покажчиками, заченням та адресую 

	int higgens = 5;
	int* pt = &higgens;

	cout << "Value of higgens = " << higgens
		<< "; Address of higgens = " << &higgens << endl;
	cout << "Value of *pt = " << *pt
		<< "; Value of pt = " << pt << endl;
	// тож саме

	int nights = 1001;
	int* pr = new int;
	*pr = 1001;

	cout << "nights value = ";
	cout << nights << ": location " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pr << ": location = " << pr << endl;
	double* pd = new double;
	*pd = 10000001.0;

	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;
	cout << "size of pt = " << sizeof(pr);
	cout << ": size of *pt = " << sizeof(*pr) << endl;
	cout << "size of pd = " << sizeof pd;
	cout << ": size of *pd = " << sizeof(*pd) << endl;
	return 0;
	// Цей код демонструє оператор new — він виділяє пам'ять у heap (купі) 
	// під час виконання програми зберігає адресу в покажчику і порівнює
	// розміри самого покажчика (sizeof pr) з розміром значення, на яке він вказує (sizeof *pr)

	double* p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 + 1;
	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 - 1;
	delete[] p3;
	return 0;
}