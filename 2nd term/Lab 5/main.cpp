#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Item {
    int key;
    string value;
    void Print() {
        cout << key << ':' << value << ' ';
    }
};

struct Node {
    int key;
    string value;
    Node *left, *right;
};

void createArray(Item* arr, int n) {
    string const cities[] = {"Moscow", "Saint-Petersburg", "New York", "London", "Paris",
                       "Tokyo", "Beijing", "Berlin", "Rome", "Madrid"};

    for (int i = 0; i < n; i++) {
        int randomIndex = rand() % 10;
        int key;
        cout << "Input key: ";
        cin >> key;

        arr[i].key = key;
        arr[i].value = cities[randomIndex];
    }
    cout << '\n';
}

void selectionSort(Item* arr, int len) {
    Item memo;

    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j].key < arr[minIndex].key) {
                minIndex = j;
            }
        }
        memo = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = memo;
    }
}

Node* createNode(int key, string value) {
    Node *newNode = new Node;
    newNode->key = key;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void createList(Node *root, int key, string value) {
    Node *prev, *cur;
    cur = root;
    while (cur != nullptr) {
        prev = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    cur = createNode(key, value);
    if (key < prev->key) {
        prev->left = cur;
    } else {
        prev->right = cur;
    }
}

void viewTree(Node *root, int level) {
    string str;

    if (root != nullptr) {
        viewTree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            str = str + " ";
        }
        cout << str << root->key << '\n';
        viewTree(root->left, level + 1);
    }

//    if (root != nullptr) {
//        viewTree(root->left, level+1);
//        string str;
//        for (int i = 0; i < level; i++) {
//            str += " ";
//        }
//        cout << str << root->key << endl;
//        viewTree(root->right, level+1);
//    }
}

void balanceTree(Node **root, int n, int len, Item *arr) {
    if (len > 0) {
        int m = n + len / 2; // Измененный способ вычисления середины диапазона
        *root = new Node;
        (*root)->key = arr[m].key;
        (*root)->value = arr[m].value;
        balanceTree(&(*root)->left, n, m - n, arr); // Левое поддерево с диапазоном от n до m-1
        balanceTree(&(*root)->right, m + 1, len - (m - n) - 1, arr); // Правое поддерево с диапазоном от m+1 до len-1
    } else {
        *root = nullptr;
    }
    /*
    if (n == len) {
        *root = nullptr;
        return;
    } else {
        int m = (n + len) / 2;
        *root = new Node;
        (*root)->value = arr[m].value;
        balanceTree(&(*root)->left, n, m, arr);
        balanceTree(&(*root)->right, m+1, len, arr);
    }
    */
}

string search(Node *root, int key) {
    if (root == nullptr) {
        return "Not found";
    }

    if (root->key == key) {
        return root->value;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node *deleteNode(Node *root, int key) {
    Node *del, *prevDel, *replace, *prevReplace;
    del = root;
    prevDel = nullptr;

    // Search item to delete
    while (del != nullptr && del->key != key) {
        prevDel = del;
        if (del->key > key) {
            del = del->left;
        } else {
            del = del->right;
        }
    }

    // Search item to replace
    if (del->right == nullptr) {
        replace = del->left;
    } else if (del->left == nullptr) {
        replace = del->right;
    }  else {
        prevReplace = del;
        replace = del->left;
        while (replace->right != nullptr) {
            prevReplace = replace;
            replace = replace->right;
        }

        if (prevReplace == del) {
            replace->right = del->right;
        } else {
            replace->right = del->right;
            prevReplace->right = replace->left;
            replace->left = prevReplace;
        }
    }

    if (del == root) {
        root = replace;
    } else {
        if (del->key < prevDel->key) {
            prevDel->left = replace;
        } else {
            prevDel->right = replace;
        }
    }
    delete del;
    return root;
}

void printStraight(Node *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->key << ":" << root->value << " ";

    printStraight(root->left);
    printStraight(root->right);
}

void printReverse(Node *root) {
    if (root == nullptr) {
        return;
    }

    printStraight(root->left);
    printStraight(root->right);

    cout << root->key << ":" << root->value << " ";
}

void printOrderKey(Node *root) {
    if (root == nullptr) {
        return;
    }

    printStraight(root->left);
    cout << root->key << ":" << root->value << " ";
    printStraight(root->right);
}

int treeDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

void deleteTree(Node *t) {
    if (t != nullptr) {
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
}

int main() {
    cout << "Input amount of arrays items: ";
    int n;
    cin >> n;

    Item *itemArr = new Item[n];
    createArray(itemArr, n);

    cout << "Created array:" << endl;
    for (int i = 0; i < n; i++) {
        itemArr[i].Print();
    }
    cout << '\n';

    Node *root;
    root = createNode(itemArr[0].key, itemArr[0].value);

    for (int i = 1; i < n; i++) {
        createList(root, itemArr[i].key, itemArr[i].value);
    }

    bool continueLoop = true;
    int choice, inputKey;
    string newValue;
    while (continueLoop) {
        cout << "View tree - 1, Balance tree - 2, Add item - 3, Search - 4, Delete item - 5, Print straight - 6, Print reverse - 7, Print in order key - 8, Tree depth - 9";
        cin >> choice;
        switch (choice) {
            case 1:
                viewTree(root, 0);
                break;
            case 2:
                selectionSort(itemArr, n);
                balanceTree(&root, 0, n, itemArr);
                cout << "Balanced Tree:" << endl;
                viewTree(root, 0);
                break;
            case 3:
                cout << "Input new key: ";
                cin >> inputKey;
                cout << "Input new value: ";
                cin >> newValue;
                createList(root, inputKey, newValue);
                break;
            case 4:
                cout << "Input key: ";
                cin >> inputKey;
                cout << search(root, inputKey);
                cout << '\n';
                break;
            case 5:
                cout << "Input key: ";
                cin >> inputKey;
                root = deleteNode(root, inputKey);
                break;
            case 6:
                printStraight(root);
                cout << '\n';
                break;
            case 7:
                printReverse(root);
                cout << '\n';
                break;
            case 8:
                printOrderKey(root);
                cout << '\n';
                break;
            case 9:
                cout << "Tree depth:" << treeDepth(root);
                cout << '\n';
                break;
            default:
                continueLoop = false;
                break;
        }
    }

    deleteTree(root);
    delete[] itemArr;

    return 0;
}