#include<iostream>
#include<clocale>
using namespace std;

struct Node {
    char data[100];
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
int listSize = 0;

void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void addToEnd(const char* str) {
    Node* newNode = new Node;
    copyString(newNode->data, str);
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) tail->next = newNode;
    tail = newNode;
    if (head == NULL) head = newNode;
    listSize++;
}

void addToStart(const char* str) {
    Node* newNode = new Node;
    copyString(newNode->data, str);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) head->prev = newNode;
    head = newNode;
    if (tail == NULL) tail = newNode;
    listSize++;
}

void addAtPosition(int pos, const char* str) {
    if (pos < 1 || pos > listSize + 1) {
        cout << "Некорректная позиция!" << endl;
        return;
    }

    if (pos == 1) {
        addToStart(str);
        return;
    }
    if (pos == listSize + 1) {
        addToEnd(str);
        return;
    }

    Node* current = head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }

    Node* newNode = new Node;
    copyString(newNode->data, str);
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    listSize++;
}

void deleteFirst() {
    if (head == NULL) {
        cout << "Список пуст!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    else tail = NULL;
    delete temp;
    listSize--;
}

void deleteLast() {
    if (tail == NULL) {
        cout << "Список пуст!" << endl;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    else head = NULL;
    delete temp;
    listSize--;
}

void deleteAfter(int pos) {
    if (pos < 1 || pos >= listSize) {
        cout << "Некорректная позиция! Нет элемента для удаления." << endl;
        return;
    }

    Node* current = head;
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }

    Node* toDelete = current->next;
    if (toDelete == tail) {
        tail = current;
        current->next = NULL;
    }
    else {
        current->next = toDelete->next;
        toDelete->next->prev = current;
    }
    delete toDelete;
    listSize--;
}

void printList() {
    if (head == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    cout << "Список (" << listSize << " элементов): ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    char str[100];
    int n;

    cout << "Кол-во элементов : ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin.getline(str, 100);
        addToEnd(str);
    }
    printList();

    cout << "\nСколько добавить в начало? ";
    int k;
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; i++) {
        cout << "Элемент: ";
        cin.getline(str, 100);
        addToStart(str);
    }
    printList();

    cout << "\nСколько добавить в конец? ";
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; i++) {
        cout << "Элемент: ";
        cin.getline(str, 100);
        addToEnd(str);
    }
    printList();

    if (listSize > 0) {
        cout << "\nНомер для вставки (от 1 до " << listSize + 1 << "): ";
        int pos;
        cin >> pos;
        cin.ignore();
        cout << "Элемент: ";
        cin.getline(str, 100);
        addAtPosition(pos, str);
        printList();
    }

    if (listSize > 1) {
        cout << "\nПосле какого номера удалить? (от 1 до " << listSize - 1 << "): ";
        int pos;
        cin >> pos;
        deleteAfter(pos);
        printList();
    }
    else if (listSize == 1) {
        cout << "\nВ списке только 1 элемент, удаление после номера невозможно." << endl;
    }

    if (listSize > 0) {
        cout << "\nУдаляем первый: ";
        deleteFirst();
        printList();
    }

    if (listSize > 0) {
        cout << "\nУдаляем последний: ";
        deleteLast();
        printList();
    }
  
    return 0;
}