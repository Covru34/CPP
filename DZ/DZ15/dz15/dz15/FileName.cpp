#include<iostream>
#include<Windows.h>
using namespace std;

//Допоміжні функції

int** createArr(int rows, int cols)
{
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];
    return arr;
}

void deleteArr(int** arr, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

void inputArr(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
}

void printArr(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }
}

//  Завдання 1

void insertCol(int**& arr, int rows, int& cols, int pos)
{
    if (pos < 0 || pos > cols) return;

    int** newArr = createArr(rows, cols + 1);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < pos; j++)
            newArr[i][j] = arr[i][j];

        newArr[i][pos] = 0; 

        for (int j = pos; j < cols; j++)
            newArr[i][j + 1] = arr[i][j];
    }

    deleteArr(arr, rows);
    arr = newArr;
    cols = cols + 1;
}

// ============ Завдання 2: видалення стовпчика ============
// pos - номер стовпчика, який видаляємо (0..cols-1)
void deleteCol(int**& arr, int rows, int& cols, int pos)
{
    if (pos < 0 || pos >= cols || cols <= 0) return;

    int** newArr = createArr(rows, cols - 1);

    for (int i = 0; i < rows; i++)
    {
        int k = 0;
        for (int j = 0; j < cols; j++)
        {
            if (j == pos) continue;
            newArr[i][k] = arr[i][j];
            k++;
        }
    }

    deleteArr(arr, rows);
    arr = newArr;
    cols = cols - 1;
}

//Завдання 3

void shiftRows(int** arr, int rows, int cols, int times, int side)
{
    if (rows == 0) return;
    times = ((times % rows) + rows) % rows; 

    for (int t = 0; t < times; t++)
    {
        if (side == 1) 
        {
            int* first = arr[0];
            for (int i = 0; i < rows - 1; i++)
                arr[i] = arr[i + 1];
            arr[rows - 1] = first;
        }
        else 
        {
            int* last = arr[rows - 1];
            for (int i = rows - 1; i > 0; i--)
                arr[i] = arr[i - 1];
            arr[0] = last;
        }
    }
}

void shiftCols(int** arr, int rows, int cols, int times, int side)
{
    if (cols == 0) return;
    times = ((times % cols) + cols) % cols;

    for (int t = 0; t < times; t++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (side == 1) 
            {
                int first = arr[i][0];
                for (int j = 0; j < cols - 1; j++)
                    arr[i][j] = arr[i][j + 1];
                arr[i][cols - 1] = first;
            }
            else 
            {
                int last = arr[i][cols - 1];
                for (int j = cols - 1; j > 0; j--)
                    arr[i][j] = arr[i][j - 1];
                arr[i][0] = last;
            }
        }
    }
}

void cyclicShift(int** arr, int rows, int cols, int direction, int times, int side)
{
    if (direction == 1)
        shiftRows(arr, rows, cols, times, side);
    else if (direction == 2)
        shiftCols(arr, rows, cols, times, side);
}

//main

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    cout << "Оберіть завдання (1 - вставка стовпчика, 2 - видалення стовпчика, 3 - циклічний зсув): ";
    cin >> choice;

    if (choice == 1)
    {
        int rows, cols, pos;
        cout << "Кількість рядків: "; cin >> rows;
        cout << "Кількість стовпців: "; cin >> cols;

        int** arr = createArr(rows, cols);
        cout << "Заповніть масив:\n";
        inputArr(arr, rows, cols);

        cout << "\nВихідний масив:\n";
        printArr(arr, rows, cols);

        cout << "\nПозиція вставки нового стовпчика (0.." << cols << "): ";
        cin >> pos;

        insertCol(arr, rows, cols, pos);

        cout << "\nРезультат:\n";
        printArr(arr, rows, cols);

        deleteArr(arr, rows);
    }
    else if (choice == 2)
    {
        int rows, cols, pos;
        cout << "Кількість рядків: "; cin >> rows;
        cout << "Кількість стовпців: "; cin >> cols;

        int** arr = createArr(rows, cols);
        cout << "Заповніть масив:\n";
        inputArr(arr, rows, cols);

        cout << "\nВихідний масив:\n";
        printArr(arr, rows, cols);

        cout << "\nНомер стовпчика для видалення (0.." << cols - 1 << "): ";
        cin >> pos;

        deleteCol(arr, rows, cols, pos);

        cout << "\nРезультат:\n";
        printArr(arr, rows, cols);

        deleteArr(arr, rows);
    }
    else if (choice == 3)
    {
        int rows, cols, direction, times, side;
        cout << "Кількість рядків (M): "; cin >> rows;
        cout << "Кількість стовпців (N): "; cin >> cols;

        int** arr = createArr(rows, cols);
        cout << "Заповніть масив:\n";
        inputArr(arr, rows, cols);

        cout << "\nВихідний масив:\n";
        printArr(arr, rows, cols);

        cout << "\nЩо зсувати? (1 - рядки, 2 - стовпці): ";
        cin >> direction;
        cout << "Кількість разів: ";
        cin >> times;
        cout << "Напрямок (1 - вгору/вліво, -1 - вниз/вправо): ";
        cin >> side;

        cyclicShift(arr, rows, cols, direction, times, side);

        cout << "\nРезультат:\n";
        printArr(arr, rows, cols);

        deleteArr(arr, rows);
    }

    return 0;
}