#include <iostream>

using namespace std;

int fibonachiNumber(int n);

int main() {
    for (;;) {
        int num;
        cout << "Введите номер: ";
        cin >> num;

        if (num == 0) {
            break;
        }

        cout << "Число под номером " << num << ": " << fibonachiNumber(num) << '\n';
        cout << '\n';
    }
}

int fibonachiNumber(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonachiNumber(n - 2) + fibonachiNumber(n - 1);
    }
}