#include <iostream>
#include <math.h>
#include <string>

using namespace std;

	// Функция для проверки
int isnumber(string s) {
	int n = 0, pt = 0, c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]))
			n++;
		else if (s[i] == '.')
			pt++;
	}
	if (pt < 2)
		c++;
	if (n + pt == s.length())
		c++;
	return c;
}

int main() {
	setlocale(LC_CTYPE, "RU");

		// Переменные и Ввод
	string a;
	int chek;
	double pr1, pr2, z1, z2, al, p = 3.1415926;
	cout << "Введите a: ";
	cin >> a;

		// Проверка введенного значения
	chek = isnumber(a);
	if (chek != 2) {
		while (chek != 2) {
			cout << "Введите a: ";
			cin >> a;
			chek = isnumber(a);
		}
	}

	al = stod(a);

		// Вычисление
	if (1 + cos(4 * al) != 0 && 1 + cos(2 * al) != 0) {
		pr1 = sin(4*al) / (1 + cos(4*al));
		pr2 = cos(2*al) / (1 + cos(2*al));
		z1 = pr1 * pr2;
	}
	else {
		cout << "Нельзя делить на ноль";
	}

	if (tan(3 / 2 * p  - al) != 0)
		z2 = 1 / tan(3 * p / 2 - al);
	else
		cout << "ctg не существует";

	cout << "Z1 = " << z1 << endl;
	cout << "Z2 = " << z2;
}