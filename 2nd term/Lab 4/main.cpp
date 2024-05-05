#include <iostream>

using namespace std;

struct Queue{
    int info;
    Queue *next;
    Queue *prev;
};

void push(Queue **queueBegin, Queue **queueTop, int item) {
    Queue *newItem = new Queue;
    newItem->info = item;

    if (*queueBegin == nullptr) {
        newItem->next = nullptr;
        newItem->prev = nullptr;
        *queueBegin = newItem;
        *queueTop = newItem;
    } else {
        newItem->next = nullptr;
        newItem->prev = *queueTop;
        (*queueTop)->next = newItem;
        *queueTop = newItem;
    }
}

void unshift(Queue **queueBegin, int item) {
    Queue *newItem = new Queue;
    newItem->info = item;
    newItem->prev = nullptr;
    newItem->next = *queueBegin;
    (*queueBegin)->prev = newItem;
    *queueBegin = newItem;
}

void readQueue_top(Queue *queueTop) {
    Queue *currentTop = queueTop;
    while (currentTop != nullptr) {
        cout << ' ' << currentTop->info;
        currentTop = currentTop->prev;
    }
    cout << '\n';
}

void readQueue_start(Queue *queueStart) {
    Queue *currentTop = queueStart;
    while (currentTop != nullptr) {
        cout << ' ' << currentTop->info;
        currentTop = currentTop->next;
    }
    cout << '\n';
}

void change(Queue **queueBegin, Queue **queueTop) {
    int topItem = (*queueTop)->info;
    (*queueTop)->info = (*queueBegin)->info;
    (*queueBegin)->info = topItem;
}

int main() {
    int n, add;
    cout << "Input amount of items:";
    cin >> n;

    Queue *top = nullptr;
    Queue *begin = nullptr;

    for (int i = 0; i < n; i++) {
        add = rand() % 21;
        push(&begin, &top, add);
    }

    int choice;
    bool continueLoop = true;
    while (continueLoop) {
        cout << "1 - Read Queue from Begin, 2 - Read Queue from Top, 3 - Add to Begin, 4 - Add to Top, 5 - Change: ";
        cin >> choice;
        switch (choice) {
            case 1:
                readQueue_top(top);
                break;
            case 2:
                readQueue_start(begin);
                break;
            case 3:
                cout << "Enter new item: ";
                cin >> add;
                push(&begin, &top, add);
                cout << "Updated queue (from top): " << endl;
                readQueue_top(top);
                break;
            case 4:
                cout << "Enter new item: ";
                cin >> add;
                unshift(&begin, add);
                cout << "Updated queue (from top): " << endl;
                readQueue_top(top);
                break;
            case 5:
                change(&begin, &top);
                cout << "Updated queue (from top): " << endl;
                readQueue_top(top);
                break;
            default:
                continueLoop = false;
                break;
        }
    }
    return 0;
}
