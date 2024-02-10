#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int fact(int n) {
    int r = 1;
    if (n > 0) {
        for (int i = 1; i <= n; i++)
            r *= i;
        return r;
    }
    else
        return r;
}

int main()
{
    setlocale(LC_ALL, "ru");

    double x, a, b, h, s = 0, y, pr;
    int i = 1, k = 0, n;

    cout << "Введите a, b, h, n" << endl;
    cin >> a >> b >> h >> n;

    cout << "№" << setw(15) << "S" << setw(15) << "Y" << setw(15) << "|Y(x) - S(X)|" << endl;

    x = a;
    while (k <= n) {
        pr = pow(-1, k) * pow(x, 2 * k) / fact(2 * k);
        s += pr;
        cout << i << setw(15) << s << setw(15) << cos(x) << setw(15) << fabs(cos(x) - s) << endl;
        x += h;
        k++;
        i++;
    }
}