#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double z1, z2, a, b, pr1, pr2, p = 3.1415926;
    cout << "Input a and b" << endl;
    cin >> a >> b;

    pr1 = cos(3 * p / 8 - b / 4) * cos(3 * p / 8 - b / 4);
    pr2 = cos(11 * p / 8 + b / 4) * cos(11 * p / 8 + b / 4);
    z1 = pr1 - pr2;

    z2 = (sqrt(2) / 2) * sin(b / 2);

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
}