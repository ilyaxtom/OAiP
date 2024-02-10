#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    string str1, str2, a;

    cout << "Enter a string: ";
    cin >> str1;

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == 'a') {
            str2.push_back(str1[i]);
            str2.push_back(str1[i]);
        }
        else
            str2.push_back(str1[i]);
        
    }

    cout << str2;
}