#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int compare(string s1, string s2) {
    int equal = 0;
    if (s1.length() > s2.length()) {
        for (int i = 0; i < s2.length(); i++) {
            if (s1[i] == s2[i])
                equal++;
        }
    }
    else if (s1.length() < s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i])
                equal++;
        }
    }
    else {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i])
                equal++;
        }
    }

    return equal;
}

int main()
{
    setlocale(LC_ALL, "ru");
    string str1, str2;

    cout << "Введите 1-ую строку: ";
    getline(cin, str1);
    cout << "Введите 2-ую строку: ";
    getline(cin, str2);

    cout << "Количество совпадающих символов: " << compare(str1, str2);
}