#include <iostream>

using namespace std;

int fibonachiNumber(int n);

int main() {
    int num;
    cin >> num;
    cout << fibonachiNumber(num);
}

int fibonachiNumber(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fibonachiNumber(n - 1) + fibonachiNumber(n -2);
    }
}