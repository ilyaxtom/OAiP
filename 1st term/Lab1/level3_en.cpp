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

int main()
{
    setlocale(LC_CTYPE, "ru");

    string snums[3], names[3] = {"x", "y", "z"};
    int chek[3];
    float nums[3], w, pr1, pr2;

    cout << "Введите x, y, z" << endl;
    for (int i = 0; i < 3; i++)
        cin >> snums[i];

    for (int i = 0; i < 3; i++)
        chek[i] = isnumber(snums[i]);

    for (int i = 0; i < 3; i++) {
        if (chek[i] != 4) {
            while (chek[i] != 4) {
                cout << "Введите " << names[i] << " заново: ";
                cin >> snums[i];
                chek[i] = isnumber(snums[i]);
            }
        }
    }

    for (int i = 0; i < 3; i++)
        nums[i] = stod(snums[i]);

    pr1 = pow(fabs(cos(nums[0]) - cos(nums[1])), 1 + 2 * sin(nums[1]) * sin(nums[1]));
    pr2 = 1 + pow(nums[2], 2) / 2. + pow(nums[2], 3) / 3. + pow(nums[2], 4) / 4.;
    w = pr1 * pr2;
    cout << w;
}