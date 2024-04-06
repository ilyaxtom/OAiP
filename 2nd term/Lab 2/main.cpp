#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int calcTime(string time);

struct Routes {
    int number;
    string destination;
    string departureTime;
    string arriveTime;
    int arriveTime_min;

    void Print() {
        cout << number << ' ' << destination << ' ' << departureTime << ' ' << arriveTime << '\n';
    }
};

void createRoutes(Routes* arr, int n);

void writeFile(ofstream& file, Routes* arr, int n);

int readFile(ifstream& file);

Routes parseString(string str);

int lineSearch(Routes* arr, int len, int n);

void selectionSort(Routes* arr, int len, ofstream& file);

void quickSort(Routes* arr, int low, int high);

int binarySearch(Routes* arr, int len, int n);

int main() {
    setlocale(LC_ALL, "ru");

    string path = "routes.txt";
    int n, choice;
    Routes* routeArr;

    cout << "Записать новый файл - 1; Использовать существующий - 2: ";
    cin >> choice;

    // Write file
    if (choice == 1) {
        cout << "Количество строк: ";
        cin >> n;
        routeArr = new Routes[n];
        createRoutes(routeArr, n);

        ofstream fileOut(path, std::ios::binary);
        writeFile(fileOut, routeArr, n);
        fileOut.close();
    }
    // Read file
    else if (choice == 2) {
        ifstream fileIn(path);

        // Lines in file
        n = 0;
        string line;
        while (getline(fileIn, line))
            ++n;

        // Start of file
        fileIn.clear();
        fileIn.seekg(0, ios::beg);

        routeArr = new Routes[n];

        for (int i = 0; i < n; ++i) {
            getline(fileIn, line);
            routeArr[i] = parseString(line);
        }

        fileIn.close();
    }
    else {
        n = 10;
        routeArr = new Routes[n];
    }

    cout << '\n';

    bool sorted = false;

    for (;;) {
        cout << "Линейный поиск - 1, Сортировка прямым выбором - 2, QuickSort - 3, Двоичный поиск - 4, Добавить маршрут - 5: ";
        cin >> choice;

        if (choice == 1) {
            int num, found;
            cout << "Введите номер элемента: ";
            cin >> num;

            found = lineSearch(routeArr, n, num);
            routeArr[found].Print();
            cout << '\n';
        }
        else if (choice == 2) {
            sorted = true;

            ofstream fileOut(path, std::ios::binary);
            selectionSort(routeArr, n, fileOut);
            fileOut.close();

            ifstream fileIn(path);
            readFile(fileIn);
            fileIn.close();
            cout << '\n';
        }
        else if (choice == 3) {
            sorted = true;

            ofstream fileOut(path, std::ios::binary);
            quickSort(routeArr, 0, n);
            writeFile(fileOut, routeArr, n);
            fileOut.close();

            ifstream fileIn(path);
            readFile(fileIn);
            fileIn.close();
            cout << '\n';
        }
        else if (choice == 4) {
            if (!sorted) {
                continue;
            }

            int found;
            string time;
            cout << "Введите время (input format: 00:00): ";
            cin >> time;

            found = binarySearch(routeArr, n, calcTime(time));
            routeArr[found].Print();
            cout << '\n';
        }
        else if (choice == 5) {
            ofstream fileOut(path, std::ios::binary);
            Routes input;
            cout << "Введите номер маршрута: ";
            cin >> input.number;
            cout << "Введите пункт назначения: ";
            cin >> input.destination;
            cout << "Введите время отправления (input format: 00:00): ";
            cin >> input.departureTime;
            cout << "Введите время прибытия (input format: 00:00): ";
            cin >> input.arriveTime;

            input.arriveTime_min = calcTime(input.arriveTime);
            fileOut << input.number << ' ' << input.destination << ' ' << input.departureTime << ' ' << input.arriveTime << '\n';
            fileOut.close();

            ifstream fileIn(path);

            n = 0;
            string line;
            while (getline(fileIn, line))
                ++n;

            fileIn.clear();
            fileIn.seekg(0, ios::beg);

            routeArr = new Routes[n];

            for (int i = 0; i < n; ++i) {
                getline(fileIn, line);
                routeArr[i] = parseString(line);
            }

            fileIn.close();
        }
        else {
            break;
        }
    }

    // Define prefer arrive time
    string prefTime;
    cout << "Введите время прибытия (input format: 00:00): ";
    cin >> prefTime;

    cout << '\n';

    // Sort routes
    cout << "Подходящие маршруты: " << endl;
    int i = 0;
    while (calcTime(prefTime) > routeArr[i].arriveTime_min) {
        cout << routeArr[i].number << ' ' << routeArr[i].destination << ' ' << routeArr[i].arriveTime << endl;
        i++;
    }

    return 0;
}

int calcTime(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

void createRoutes(Routes* arr, int n) {
    string sities[8] = { "Minsk", "Grodno", "Gomel", "Vitebsk", "Berlin", "Moscow", "Kiev", "Riga" };
    const int n_sities = 7;

    for (int i = 0; i < n; i++) {
        // Number and Destination
        arr[i].number = i + 1;
        arr[i].destination = sities[0 + rand() % n_sities];

        // Departure time
        int depHour = 10 + rand() % 13;
        int depMin = 10 + rand() % 49;
        arr[i].departureTime = to_string(depHour) + ":" + to_string(depMin);

        // Arrive time
        int arrHour = 10 + rand() % 13;
        int arrMin = 10 + rand() % 49;
        arr[i].arriveTime = to_string(arrHour) + ":" + to_string(arrMin);
        arr[i].arriveTime_min = calcTime(arr[i].arriveTime);

        cout << i + 1 << ' ' << arr[i].destination << ' ' << arr[i].departureTime << " - " << arr[i].arriveTime << endl;
    }
    cout << '\n';
}

void writeFile(ofstream& file, Routes* arr, int n) {
    for (int i = 0; i < n; i++) {
        file << arr[i].number << ' ' << arr[i].destination << ' ' << arr[i].departureTime << ' ' << arr[i].arriveTime << '\n';
    }
}

int readFile(ifstream& file) {
    string str;
    int i = 0;
    while (!file.eof()) {
        str = "";
        getline(file, str);
        cout << str << endl;
        i++;
    }
    return i - 1;
}

int lineSearch(Routes* arr, int len, int n) {
    for (int i = 0; i < len; i++) {
        if (arr[i].number == n) {
            return i;
        }
    }
}

Routes parseString(string str) {
    Routes route;

    size_t pos1 = str.find(' ');
    size_t pos2 = str.find(' ', pos1 + 1);
    size_t pos3 = str.find(' ', pos2 + 1);

    route.number = stoi(str.substr(0, pos1));
    route.destination = str.substr(pos1 + 1, pos2 - pos1 - 1);
    route.departureTime = str.substr(pos2 + 1, pos3 - pos2 - 1);
    route.arriveTime = str.substr(pos3 + 1);
    route.arriveTime_min = calcTime(route.arriveTime);

    return route;
}

void selectionSort(Routes* arr, int len, ofstream& file) {
    Routes memo;

    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j].arriveTime_min < arr[minIndex].arriveTime_min) {
                minIndex = j;
            }
        }
        memo = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = memo;
    }

    writeFile(file, arr, len);
}

void quickSort(Routes* arr, int low, int high) {
    if (low < high) {
        int i = low;
        int j = high - 1;
        int x = arr[(low + high) / 2].arriveTime_min;
        Routes memo;

        while (i <= j) {
            while (arr[i].arriveTime_min < x)
                i++;
            while (arr[j].arriveTime_min > x)
                j--;

            if (i <= j) {
                memo = arr[i];
                arr[i] = arr[j];
                arr[j] = memo;
                i++;
                j--;
            }
        }

        quickSort(arr, low, j);
        quickSort(arr, i, high);
    }
}

int binarySearch(Routes *arr, int len, int n) {
    int low = 0;
    int high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Если найден элемент, возвращаем его индекс
        if (arr[mid].arriveTime_min == n)
            return mid;

        // Если искомый элемент меньше элемента в середине, ищем в левой половине массива
        if (arr[mid].arriveTime_min > n)
            high = mid - 1;
        // Если искомый элемент больше элемента в середине, ищем в правой половине массива
        else
            low = mid + 1;
    }
}