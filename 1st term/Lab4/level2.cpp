#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int min, n, summ = 0, num = 0, mas[10];

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

    cout << endl;

    for (int i = 0; i < 10; i++) {
        if (mas[i] > 0) {
            mas[num] = mas[i];
            num++;
        }
    }

    cout << "Новый массив: ";
    for (int i = 0; i < num; i++) {
        cout << mas[i] << " ";
    }
}