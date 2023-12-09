#include <iostream>
#include <math.h>
#include <string>

using namespace std;

// функция проверяющая является ли введенная строка числом
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

int main()
{
    setlocale(LC_CTYPE, "ru");

    double z, b, x, y;
    int chek[2];
    string strnums[2], names[2] = { "z", "b" };

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
    b = stod(strnums[1]);

    if (z < 1) {
        cout << "Выбрана первая ветвь" << endl;
        x = pow(x, 3) + 0.2;
    }
    else {
        cout << "Выбрана вторая ветвь" << endl;
        x = z + log(z);
    }

    y = pow(cos(x * x), 3) + pow(sin(x * x * x), 2);
    cout << "y = " << y;
}