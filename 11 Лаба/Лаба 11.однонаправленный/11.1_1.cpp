#include <iostream>
#include <clocale>

using namespace std;


void copyStr(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

struct Node
{
    char data[100];
    Node* next_ptr;

    void addData(const char* Data)
    {
        copyStr(data, Data); 
        next_ptr = nullptr;
    }
};

struct List
{
    Node* head = nullptr;
    Node* tail = nullptr;

    
    void push_back(const char* data)
    {
        Node* node = new Node;
        node->addData(data);

        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next_ptr = node;
            tail = node;
        }
    }

    
    void deleteAfter(int number)
    {
        if (!head) return;

        Node* current = head;
        int count = 1;

        while (current && count < number)
        {
            current = current->next_ptr;
            count++;
        }

        if (!current || !current->next_ptr) return;

        Node* toDelete = current->next_ptr;
        current->next_ptr = toDelete->next_ptr;

        if (toDelete == tail)
            tail = current;

        delete toDelete;
    }

  
    void deleteHead()
    {
        if (!head) return;

        Node* temp = head;
        head = head->next_ptr;

        if (!head)
            tail = nullptr;

        delete temp;
    }

   
    void deleteTail()
    {
        if (!head) return;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next_ptr != tail)
            temp = temp->next_ptr;

        delete tail;
        tail = temp;
        tail->next_ptr = nullptr;
    }

    
    void addKToBeginning(int K)
    {
        for (int i = 0; i < K; i++)
        {
            char str[100];
            cout << "Введите строку: ";
            cin >> str;

            Node* newNode = new Node;
            newNode->addData(str);

            newNode->next_ptr = head;
            head = newNode;

            if (!tail)
                tail = newNode;
        }
    }

   
    void addAt(int pos, const char* value)
    {
        if (pos == 1)
        {
            Node* newNode = new Node;
            newNode->addData(value);

            newNode->next_ptr = head;
            head = newNode;

            if (!tail)
                tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next_ptr;

        if (!temp) return;

        Node* newNode = new Node;
        newNode->addData(value);

        newNode->next_ptr = temp->next_ptr;
        temp->next_ptr = newNode;

        if (temp == tail)
            tail = newNode;
    }

    void print()
    {
        Node* node = head;
        while (node)
        {
            cout << node->data << " -> ";
            node = node->next_ptr;
        }
        cout << "NULL\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    List list;
    int n;
    char str[100];

    cout << "Введите размер списка: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Введите строку: ";
        cin >> str;
        list.push_back(str);
    }

    cout << "\nСписок: ";
    list.print();

    int pos;
    cout << "\nУдалить после номера: ";
    cin >> pos;
    list.deleteAfter(pos);

    cout << "После deleteAfter: ";
    list.print();

    list.deleteHead();
    cout << "После удаления из начала: ";
    list.print();

    list.deleteTail();
    cout << "После удаления с конца: ";
    list.print();

    int k;
    cout << "Сколько добавить в начало: ";
    cin >> k;
    list.addKToBeginning(k);

    cout << "После добавления в начало: ";
    list.print();
    cout << "Добавить в конец: ";
    cin >> str;
    list.push_back(str);

    cout << "После добавления в конец: ";
    list.print();

    cout << "Добавить по позиции (позиция и строка): ";
    cin >> pos >> str;
    list.addAt(pos, str);

    cout << "Итоговый список: ";
    list.print();

    return 0;
}