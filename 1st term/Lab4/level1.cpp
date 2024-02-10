#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    double min, n, summ = 0, mas[10];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> mas[i];
    }

    min = mas[0];
    n = 0;
    for (int i = 0; i < 10; i++) {
        if (mas[i] < min) {
            min = mas[i];
            n = i;
        }
    }

    if (n == 0) {
        cout << "Сумма: " << 0;
    }
    else {
        for (int i = 0; i < n; i++) {
            summ += mas[i];
        }
        cout << "Сумма: " << summ;
    }

}