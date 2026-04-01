#include <iostream>
#include<clocale>
using namespace std;

struct Node {
    char key[100];
    Node* next;
};

Node* createNode(char value[]) {
    Node* newNode = new Node;

    int i = 0;
    while (value[i] != '\0') {
        newNode->key[i] = value[i];
        i++;
    }
    newNode->key[i] = '\0';

    newNode->next = NULL;
    return newNode;
}

void addToStart(Node*& head, char value[]) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    cout << "Добавлено в начало: " << value << endl;
}


void deleteFromStart(Node*& head) {
    if (head == NULL) {
        cout << "Список пуст" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "Удалено из начала: " << temp->key << endl;
    delete temp;
}


void showList(Node* head) {
    if (head == NULL) {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "\nТекущий список:" << endl;
    Node* temp = head;
    int num = 1;
    while (temp != NULL) {
        cout << num << ". " << temp->key << endl;
        temp = temp->next;
        num++;
    }
    cout << endl;
}

void clearList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");
    Node* head = NULL;
    char text[100];
    int k, pos;
    
    cout << "Сколько элементов добавить? ";
    cin >> k;
    cin.get();  

    for (int i = 0; i < k; i++) {
        cout << "Элемент " << (i + 1) << ": ";
        cin.getline(text, 100);
        addToStart(head, text);
    }
    showList(head);

    cout << "\n УДАЛЕНИЕ ИЗ НАЧАЛА " << endl;
    deleteFromStart(head);
    showList(head);


    cout << "\n ДОБАВЛЕНИЕ В НАЧАЛО " << endl;
    cout << "Сколько добавить в начало? ";
    cin >> k;
    cin.get();

    for (int i = 0; i < k; i++) {
        cout << "Элемент " << (i + 1) << " в начало: ";
        cin.getline(text, 100);
        addToStart(head, text);
    }
    showList(head);



    return 0;
}