#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n, m, ** array, choice, summ, special = 0;
    cout << "Введите размер матрицы" << endl;
    cin >> n >> m;
    array = new int* [n];
    for (int i = 0; i < n; i++)
        array[i] = new int[m];

    cout << "Как заполнить массив? 1 - с клавиатуры, 2 - случайные числа" << endl;
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            cout << "Введите " << m << " элемента(ов) " << i + 1 << " строки" << endl;
            for (int j = 0; j < m; j++)
                cin >> array[i][j];
        }
        cout << "Созданный массив" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << array[i][j] << setw(5);
            cout << setw(0) << endl;
        }
    }
    else {
        cout << "Созданный массив" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                array[i][j] = -50 + rand() % 100;
                cout << array[i][j] << setw(5);
            }
            cout << setw(0) << endl;
        }
    }

    for (int j = 0; j < m; j++) {
        summ = 0;
        for (int i = 0; i < n; i++)
            summ += array[i][j];
        for (int i = 0; i < n; i++) {
            if (array[i][j] > summ - array[i][j])
                special++;
        }
    }

    cout << "Количество особых элементов: " << special;
}