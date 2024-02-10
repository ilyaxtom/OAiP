#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int isnumber(string s) {
    int n = 0, pt = 0, c = 0, e = 0, min = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]))
            n++;
        else if (s[i] == '.')
            pt++;
        else if (s[i] == 'e')
            e++;
        else if (s[i] == '-')
            min++;
    }
    if (pt < 2)
        c++;
    if (n + pt + e + min == s.length())
        c++;
    if (e < 2)
        c++;
    if (min < 3)
        c++;
    return c;
}

int isint(string s) {
    int n = 0, c;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]))
            n++;
    }
    if (n = s.length())
        c = 4;
    return c;
}

int main()
{
    setlocale(LC_ALL, "ru");

    double x, z, a,func, y, b, p = 3.141592;
    int chek[3], f;
    string strnums[3], names[2] = { "z", "a"};

    for (int i = 0; i < 2; i++) {
        cout << "Введите " << names[i] << " : ";
        cin >> strnums[i];
    }

    for (int i = 0; i < 2; i++) {
        chek[i] = isnumber(strnums[i]);
        if (chek[i] != 4) {
            while (chek[i] != 4) {
                cout << "Введите " << names[i] << " заново: ";
                cin >> strnums[i];
                chek[i] = isnumber(strnums[i]);
            }
        }
    }

    z = stod(strnums[0]);
    a = stod(strnums[1]);

    cout << "Выберете функцию: 1 - 2x, 2 - x^2, 3 - x/3: ";
    cin >> strnums[2];

    chek[2] = isint(strnums[2]);
    if (chek[2] != 4) {
        while (chek[2] != 4) {
            cout << "Выберете функцию заново: ";
            cin >> strnums[2];
            chek[2] = isint(strnums[2]);
        }
    }

    f = stoi(strnums[2]);
    if (f > 3) {
        while (f > 3) {
            cout << "Выберете функцию заново: ";
            cin >> f;
        }
    }

    switch (f) {
    case 1:
        func = 2 * z;
        break;
    case 2:
        func = z * z;
        break;
    case 3:
        func = z / 3;
        break;
    }

    if (z < 1) {
        cout << "Выбрана первая ветвь" << endl;
        x = pow(z, 3) + 0.2;
    }
    else {
        cout << "Выбрана вторая ветвь" << endl;
        x = z + log(z);
    }
    
    b = 34;
    y = 2 * a * pow(cos(x * x), 3) + pow(sin(x * x), 2) - b * func;
    cout << "y = " << y;
}