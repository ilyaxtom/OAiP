#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void calc(int func) {
    double x = 0.1;
    int i = 1;
    
    if (func == 1) {
        cout << '№' << setw(15) << "Y(x)" << '\n';
        for (x; x <= 1; x += 0.1) {
            cout << i << setw(15) << cos(x) << '\n';
            i++;
        }
    }
    else if (func == 2) {
        int n, k;
        double s = 1, mult, s_el = 1;
        cout << "Введите n: ";
        cin >> n;

        cout << '№' << setw(15) << "S(x)" << '\n';
        for (x; x <= 1; x += 0.1) {
            for (k = 1; k <= n; k++) {
                mult = (-1 * x * x) / (4 * k * k - 2 * k);
                s_el *= mult;
                s += s_el;
            }
            cout << i << setw(15) << s << '\n';
            s = 1;
            s_el = 1;
            i++;
        }
    }
    else if (func == 3) {
        int n, k;
        double s = 1, mult, s_el = 1;
        cout << "Введите n: ";
        cin >> n;

        cout << '№' << setw(15) << "|Y(x) - S(x)|" << '\n';
        for (x; x <= 1; x += 0.1) {
            for (k = 1; k <= n; k++) {
                mult = (-1 * x * x) / (4 * k * k - 2 * k);
                s_el *= mult;
                s += s_el;
            }
            cout << i << setw(15) << fabs(cos(x) - s) << '\n';
            s = 1;
            s_el = 1;
            i++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    int request;

    for (;;) {
        cout << "Выберете функцию: 1 - Y(x), 2 - S(x), 3 - |Y(x) - S(x)|, 0 - для выхода" << '\n';
        cin >> request;

        if (request == 0)
            break;
        else
            calc(request);

        cout << '\n';
    }

    return 0;
}