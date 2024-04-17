#include <iostream>

using  namespace std;

struct Stack{
    int info;
    Stack *next;
};

Stack *push(Stack *stackTop, int add) {
    Stack *newItem = new Stack;
    newItem -> info = add;
    newItem -> next = stackTop;
    return newItem;
}

Stack *deleteItem(Stack *stackTop) {
    if (stackTop->next == nullptr)
        return stackTop;

    Stack *spt = stackTop;
    stackTop = stackTop->next;
    delete spt;
    return stackTop;
}

void readStack(Stack *stackTop) {
    Stack *currentTop = stackTop;
    while (currentTop != nullptr) {
        cout << ' ' << currentTop -> info << endl;
        currentTop = currentTop -> next;
    }
}

void RevStackAfter(Stack *stackTop) {
    Stack *spt = stackTop->next->next;
    stackTop->next->next = spt->next;
    spt->next = stackTop->next;
    stackTop->next = spt;
}

void addressSort(Stack *stackTop) {
    if(stackTop->next->next == nullptr)
        return;

    Stack *spt = nullptr, *spm;
    do {
        for (spm = stackTop; spm->next->next != spt; spm = spm->next) {
            if (spm->next->info > spm->next->next->info)
                RevStackAfter(spm);
        }
        spt = spm -> next;
    } while (stackTop->next->next != spt);
}

void sortStack(Stack *stackTop) {
    Stack *t = nullptr, *t1;
    int r;

    do {
        for (t1 = stackTop; t1 -> next != t; t1 = t1 -> next) {
            if (t1 -> info > t1->next->info) {
                r = t1 -> info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        }
        t = t1;
    } while (stackTop->next != t);

    cout << "Stack contents after sorting:" << endl;
    readStack(stackTop);
}

void change(Stack *stackTop) {
    int topItem = stackTop->info;
    Stack *currentTop = stackTop;

    while (currentTop->next != nullptr) {
        currentTop = currentTop->next;
    }

    stackTop->info = currentTop->info;
    currentTop->info = topItem;

    cout << "Stack contents after changing:" << endl;
    readStack(stackTop);
}

int main() {
    int n, add;
    cout << "Input amount of items:";
    cin >> n;

    Stack *top = nullptr;

    for (int i = 0; i < n; i++) {
        add = rand() % 21;
        top = push(top, add);
    }


    cout << "Stack contents:" << endl;
    readStack(top);

    int choice;
    bool continueLoop = true;
    while (continueLoop) {
        cout << "1 - Read Stack, 2 - Address Sort, 3 - Values Sort, 4 - Change: ";
        cin >> choice;
        switch (choice) {
            case 1:
                readStack(top);
                break;
            case 2:
                top = push(top, 66);
                addressSort(top);
                top = deleteItem(top);
                readStack(top);
                break;
            case 3:
                sortStack(top);
                break;
            case 4:
                change(top);
                break;
            default:
                continueLoop = false;
                break;
        }
    }

    return 0;
}