#include <iostream>
#include <math.h>

using namespace std;

    //функция для проверки выбора функции
void countf(double x, double y, int k, double *func, bool *ch) {
    switch (k) {
    case 1: *func = sinh(x); *ch = true; break;
    case 2: *func = x * x; *ch = true; break;
    case 3: *func = exp(x); *ch = true; break;
    default: *ch = false;
    }
}

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
    setlocale(LC_ALL, "ru");
        //объявление и ввод переменных
    double x, y, f, a, c;
    int k;
    bool chekf;

    cout << "Введите x, y" << endl;
    cin >> x >> y;

    cout << "Выберите функцию: 1 - sh(f), 2 - x^2, 3 - e^x" << endl;
    cin >> k;

        //проверка выбора и вычисление значения функции
    countf(x, y, k, &f, &chekf);
    while (!chekf) {
        cout << "Выберите функцию заново:" << endl;
        cin >> k;
        countf(x, y, k, &f, &chekf);
    }

        //выбор ветви вычисления и расчет значения с
    a = x - y;
    if (a == 0) {
        cout << "Выбрана 1-ая ветвь вычислений" << endl;
        c = f * f + cbrt(y) + sin(y);
    }
    else if (a > 0) {
        cout << "Выбрана 2-ая ветвь вычислений" << endl;
        c = pow(f - y, 2) + log(x);
    }
    else {

        cout << "Выбрана 3-ая ветвь вычислений" << endl;
        c = pow(y - f, 2) + tan(y);
    }
        //вывод результата
    cout << "c = " << c;

    return 0;
}