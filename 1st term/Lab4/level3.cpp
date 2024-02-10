#include <iostream>
#include <stdlib.h>

using namespace std;

int sort(int m[10]) {
    int negative[10], new_mas[10], num_neg = 0;

    for (int i = 0; i < 10; i++) {
        if (m[i] < 0) {
            new_mas[num_neg] = m[i];
            num_neg++;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (m[i] >= 0) {
            new_mas[num_neg] = m[i];
            num_neg++;
        }
    }

    cout << endl;
    cout << "Новый массив: ";
    for (int i = 0; i < 10; i++)
        cout << new_mas[i] << " ";

    return 0;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int* mas = new int[10];
    int n, new_arr[10];

    cout << "Как заполнить массив? 1 - с клавиатуры, 2 - случайные числа" << endl;
    cin >> n;

    if (n == 1) {
        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < 10; i++)
            cin >> mas[i];
    }
    else {
        cout << "Созданный массив: ";
        for (int i = 0; i < 10; i++) {
            mas[i] = -50 + rand() % 100;
            cout << mas[i] << " ";
        }

    }

    sort(mas);
    delete[] mas;
}