#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n, m, choice, ** array, * comp_negative;
    bool* negative;
    cout << "Введите размер массива" << endl;
    cin >> n >> m;
    array = new int* [n];
    negative = new bool [n];
    comp_negative = new int [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int [m];
        comp_negative[i] = 1;
        negative[i] = false;
    }

    cout << "Как заполнить массив? 1 - с клавиатуры, 2 - случайные числа" << endl;
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            cout << "Введите " << m << " элемента(ов) " << i + 1 << " строки" << endl;
            for (int j = 0; j < m; j++) {
                cin >> array[i][j];
                if (array[i][j] < 0)
                    negative[i] = true;
            }      
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
                if (array[i][j] < 0)
                    negative[i] = true;
                cout << array[i][j] << setw(5);
            }
            cout << setw(0)<< endl;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (negative[i] == false) {
                comp_negative[i] *= array[i][j];
            }
            else
                comp_negative[i] = 0;
        }
        cout << "Произведение " << i + 1 << " строки: " << comp_negative[i] << endl;
    }
}