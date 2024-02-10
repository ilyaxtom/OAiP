#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    setlocale(LC_ALL, "ru");

    int n;

    for (;;) {
        cout << "Введите n: ";
        cin >> n;

        if (n == 0)
            break;
        else {
            while (n < 1)
                cin >> n;
            cout << "Fb(n) = " << fib(n) << '\n';

            cout << '\n';
        }
    }
}