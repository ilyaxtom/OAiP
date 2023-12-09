#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    double x, y, a, b, h, max, min, p = 3.141592;
    int i = 1;

    cout << "Введите a, b, h:" << endl;
    cin >> a >> b >> h;

    cout << "№" << setw(5) << "X" << setw(15) << "Y" << endl;

    min = y = (1 - a * a / 4.) * cos(a) - a * sin(a) / 2;
    max = min;

    for (x = a; x <= b; x += h) {
        y = (1 - x * x / 4.) * cos(x) - x * sin(x) / 2;
        if (y < min)
            min = y;
        if (y > max)
            max = y;
        cout << i << setw(10) << x << setw(15) << y << endl;
        i++;
    }
    cout << "max = " << max << endl;
    cout << "min = " << min;
}