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
    int unsigned arriveTime_min;

    void Print() {
        cout << number << ' ' << destination << ' ' << departureTime << ' ' << arriveTime << endl;
    }
};

void createRoutes(Routes *arr, int n, string sities[], int n_sities);

int main() {
    // Initialize array of sities
    string sities[8] = {"Minsk", "Grodno", "Gomel", "Vitebsk", "Berlin", "Moscow", "Kiev", "Riga"};
    const int numSities = 7;

    // Define number of routes and initialize routes array
    int n;
    cout << "n = ";
    cin >> n;
    Routes *routeArr = new Routes[n];
    createRoutes(routeArr, n, sities, numSities);

    string path = "routes.txt";
    ofstream fileOut(path, ofstream::app);

    for (int i = 0; i < n; i++) {
        fileOut.write((char*)&routeArr[i], sizeof(routeArr[i]));
    }



    // // Define prefer arrive time
    // string prefTime;
    // cout << "Enter prefer time (input format: 00:00): ";
    // cin >> prefTime;

    // cout << '\n';

    // // Sort routes
    // cout << "Suitable routes: " << endl;
    // for (int i = 0; i < n; i++) {
    //     if ( routeArr[i].arriveTime_min < calcTime(prefTime) ) {
    //         cout << routeArr[i].number << ' ' << routeArr[i].destination << ' ' << routeArr[i].arriveTime << endl;
    //     }
    // }

    return 0;
}

int calcTime(string time) {
    return stoi( time.substr(0, 2) ) * 60 + stoi( time.substr(3, 2) );
}

void createRoutes(Routes *arr, int n, string sities[], int n_sities) {
    for (int i = 0; i < n; i++) {
        // Number and Destination
        arr[i].number = i + 1;
        arr[i].destination = sities[0 + random() % n_sities];

        // Departure time
        int depHour = 10 + random() % 13;
        int depMin = 10 + random() % 49;
        arr[i].departureTime = to_string(depHour) + ":" + to_string(depMin);

        // Arrive time
        int arrHour = 10 + random() % 13;
        int arrMin = 10 + random() % 49;
        arr[i].arriveTime = to_string(arrHour) + ":" + to_string(arrMin);
        arr[i].arriveTime_min = calcTime( arr[i].arriveTime ); 

        cout << i + 1 << ' ' << arr[i].destination<< ' ' << arr[i].departureTime << " - " << arr[i].arriveTime << endl;
    }
    cout << '\n';
}