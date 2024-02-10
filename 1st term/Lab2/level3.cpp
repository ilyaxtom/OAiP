#include <iostream>
#include <string>

using namespace std;
    //функция для проверки нечисловых значений
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
    //функции для определения минимального (максимального) элемента
double minimum(double a, double b) {
    if (a < b)
        return a;
    else
        return b;
}

double maximum(double a, double b) {
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    setlocale(LC_ALL, "ru");
        //объявление и ввод переменных
    double m, nums[3];
    int chek[3];
    string strnums[3], names[3] = { "x", "y", "z" };

    for (int i = 0; i < 3; i++) {
        cout << "Введите " << names[i] << " : ";
        cin >> strnums[i];
    }
        //проверка введеных значений
    for (int i = 0; i < 3; i++) {
        chek[i] = isnumber(strnums[i]);
        if (chek[i] != 4) {
            while (chek[i] != 4) {
                cout << "Введите " << names[i] << " заново: ";
                cin >> strnums[i];
                chek[i] = isnumber(strnums[i]);
            }
        }
    }

    for (int i = 0; i < 3; i++)
        nums[i] = stod(strnums[i]);
        //расчет значения m
    if (nums[1] != 0 && nums[2] != 0) {
        m = (minimum(maximum(nums[0], nums[1]), maximum(nums[1], nums[2]))) / maximum(nums[1], nums[2]);
        cout << "m = " << m;
    }
    else
        cout << "Error";
}