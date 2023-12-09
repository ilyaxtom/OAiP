#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    string str;
    int group_length = 0, group_start = 0;
    cout << "Введите строку: ";
    getline(cin, str);

    cout << "Строки с четным количеством символов: ";

    for (int i = 0; i < str.length(); i++) {
        group_length++;
        if (str[i] == ' ' && (group_length - 1) % 2 == 0) {
            for (int j = group_start; j < i; j++)
                cout << str[j];
            group_start = i + 1;
            group_length = 0;
            cout << ' ';
        }
        else if (str[i] == ' ' && (group_length - 1) % 2 != 0) {
            group_start = i + 1;
            group_length = 0;
        }
        else if (i == str.length() - 1 && group_length % 2 == 0) {
            for (int j = group_start; j <= i; j++)
                cout << str[j];
        }
    }
    return 0;
}