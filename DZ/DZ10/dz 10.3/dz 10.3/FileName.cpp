#include<iostream>
#include<Windows.h>
#include<cmath>
using namespace std;

const int MAX_N = 10;

// для int

void initMatrix(int matrix[][MAX_N], int n);

void printMatrix(int matrix[][MAX_N], int n);

void diagMinMax(int matrix[][MAX_N], int n, int& minVal, int& maxVal);

void sortRows(int matrix[][MAX_N], int n);

//для double

void initMatrix(double matrix[][MAX_N], int n);

void printMatrix(double matrix[][MAX_N], int n);

void diagMinMax(double matrix[][MAX_N], int n, double& minVal, double& maxVal);

void sortRows(double matrix[][MAX_N], int n);

// для char

void initMatrix(char matrix[][MAX_N], int n);

void printMatrix(char matrix[][MAX_N], int n);

void diagMinMax(char matrix[][MAX_N], int n, char& minVal, char& maxVal);

void sortRows(char matrix[][MAX_N], int n);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int n;
	cout << "Введіть розмір матриці: \n";
	cin >> n;

	// int
	cout << "\n=== Матриця int ===" << endl;
	int imat[MAX_N][MAX_N];  
	int imin, imax;           

	initMatrix(imat, n);      
	cout << "Вихідна матриця:" << endl;
	printMatrix(imat, n);     
	diagMinMax(imat, n, imin, imax);  
	cout << "Мін на діагоналі: " << imin << endl;
	cout << "Макс на діагоналі: " << imax << endl;
	sortRows(imat, n);        
	cout << "Після сортування:" << endl;
	printMatrix(imat, n);     

	//double
	cout << "\n=== Матриця double ===" << endl;
	double dmat[MAX_N][MAX_N];
	double dmin, dmax;

	initMatrix(dmat, n);
	cout << "Вихідна матриця:" << endl;
	printMatrix(dmat, n);
	diagMinMax(dmat, n, dmin, dmax);
	cout << "Мін на діагоналі: " << dmin << endl;
	cout << "Макс на діагоналі: " << dmax << endl;
	sortRows(dmat, n);
	cout << "Після сортування:" << endl;
	printMatrix(dmat, n);

	// char
	cout << "\n=== Матриця char ===" << endl;
	char cmat[MAX_N][MAX_N];
	char cmin, cmax;

	initMatrix(cmat, n);
	cout << "Вихідна матриця:" << endl;
	printMatrix(cmat, n);
	diagMinMax(cmat, n, cmin, cmax);
	cout << "Мін на діагоналі: " << cmin << endl;
	cout << "Макс на діагоналі: " << cmax << endl;
	sortRows(cmat, n);
	cout << "Після сортування:" << endl;
	printMatrix(cmat, n);

	return 0;
}

// int

void initMatrix(int matrix[][MAX_N], int n)
{
	cout << "Введіть " << n * n << " цілих чисел: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(int matrix[][MAX_N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void diagMinMax(int matrix[][MAX_N], int n, int& minVal, int& maxVal)
{
	minVal = maxVal = matrix[0][0];
	for (int i = 1; i < n; i++)
	{
		if (matrix[i][i] < minVal) minVal = matrix[i][i];
		if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
	}
}

void sortRows(int matrix[][MAX_N], int n)
{
	for (int i = 0; i < n; i++) // проходимся по рядкам
		for (int a = 0; a < n - 1; a++) //проходимся по першому(0) елементу в рядку
			for (int b = a + 1; b < n; b++) //проходимся по другому елементу врядку( другий елемент більше за перший на 1, тому b = a+1)
				if (matrix[i][a] > matrix[i][b]) //якщо перший елемент(а) більше за другий елемент(b), то міняємо їх місцями, тому що ми ідемо по наростающій, від меншого до більшого
					swap(matrix[i][a], matrix[i][b]);
}

// double

void initMatrix(double matrix[][MAX_N], int n)
{
	cout << "Введіть " << n * n << " цілих чисел: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(double matrix[][MAX_N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void diagMinMax(double matrix[][MAX_N], int n, double& minVal, double& maxVal)
{
	minVal = maxVal = matrix[0][0];
	for (int i = 1; i < n; i++)
	{
		if (matrix[i][i] < minVal) minVal = matrix[i][i];
		if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
	}
}

void sortRows(double matrix[][MAX_N], int n)
{
	for (int i = 0; i < n; i++) // проходимся по рядкам
		for (int a = 0; a < n - 1; a++) //проходимся по першому(0) елементу в рядку
			for (int b = a + 1; b < n; b++) //проходимся по другому елементу врядку( другий елемент більше за перший на 1, тому b = a+1)
				if (matrix[i][a] > matrix[i][b]) //якщо перший елемент(а) більше за другий елемент(b), то міняємо їх місцями, тому що ми ідемо по наростающій, від меншого до більшого
					swap(matrix[i][a], matrix[i][b]);
}

// char

void initMatrix(char matrix[][MAX_N], int n)
{
	cout << "Введіть " << n * n << " цілих чисел: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(char matrix[][MAX_N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void diagMinMax(char matrix[][MAX_N], int n, char& minVal, char& maxVal)
{
	minVal = maxVal = matrix[0][0];
	for (int i = 1; i < n; i++)
	{
		if (matrix[i][i] < minVal) minVal = matrix[i][i];
		if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
	}
}

void sortRows(char matrix[][MAX_N], int n)
{
	for (int i = 0; i < n; i++) // проходимся по рядкам
		for (int a = 0; a < n - 1; a++) //проходимся по першому(0) елементу в рядку
			for (int b = a + 1; b < n; b++) //проходимся по другому елементу врядку( другий елемент більше за перший на 1, тому b = a+1)
				if (matrix[i][a] > matrix[i][b]) //якщо перший елемент(а) більше за другий елемент(b), то міняємо їх місцями, тому що ми ідемо по наростающій, від меншого до більшого
					swap(matrix[i][a], matrix[i][b]);
}