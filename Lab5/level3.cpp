#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int** arr, ** new_arr, n, i, j, choice;

    cout << "Введите n: ";
    cin >> n;

    arr = new int* [n];
    new_arr = new int* [n];

    for (i = 0; i < n; i++) {
        arr[i] = new int[n];
        new_arr[i] = new int[n];
    }

    cout << "Как заполнить массив? 1 - с клавиатуры, 2 - случайные числа" << endl;
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            cout << "Введите " << n << " элемента(ов) " << i + 1 << " строки" << endl;
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        cout << "Созданный массив:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << setw(5);
            cout << setw(0) << endl;
        }
    }
    else {
        cout << "Созданный массив:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0 + rand() % 2;
                cout << arr[i][j] << setw(5);
            }
            cout << setw(0) << endl;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            new_arr[j][n - i - 1] = arr[i][j];
    }

    cout << "Новый массив:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << new_arr[i][j] << setw(5);
        cout << '\n';
    }

    delete arr, new_arr;

    return 0;
}