#include <iostream>

using namespace std;

int fibRec(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fibRec(n - 1) + fibRec(n - 2);
}

int fib(int n) {
    int fn_2 = 0, fn_1 = 1, f;
    
    if (n == 1)
        return 1;
    else {
        for (int i = 2; i <= n; i++) {
            f = fn_2 + fn_1;
            fn_2 = fn_1;
            fn_1 = f;
        }
        return fn_1;
    }
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
            cout << "Rec Fb(n) = " << fibRec(n) << '\n';

            cout << '\n';
        }
    }
}