#include <iostream>
#include <clocale>
#include <cstring>
using namespace std;

struct Node
{
    char* data;  
    Node* next_ptr;
};

struct Queue
{
    int size;
    Node* head;
    Node* tail;

    void initQueue(Queue& q, const char* value) 
    {
        Node* newNode = new Node;
        newNode->data = new char[strlen(value) + 1];
        
        for (int i = 0; i <= strlen(value); i++)
        {
            newNode->data[i] = value[i];
        }
        newNode->next_ptr = nullptr;
        q.head = newNode;
        q.tail = newNode;
        q.size = 1;
    }

    void push(Queue& q, const char* data)
    {
        Node* newNode = new Node;
        newNode->data = new char[strlen(data) + 1];
      
        for (int i = 0; i <= strlen(data); i++)
        {
            newNode->data[i] = data[i];
        }
        newNode->next_ptr = nullptr;

        if (q.head == nullptr)
        {
            q.head = newNode;
            q.tail = newNode;
        }
        else
        {
            q.tail->next_ptr = newNode;
            q.tail = newNode;
        }
        q.size++;
        return;
    }

    void push_front(Queue& q, const char* data)
    {
        Node* newNode = new Node;
        newNode->data = new char[strlen(data) + 1];
      
        for (int i = 0; i <= strlen(data); i++)
        {
            newNode->data[i] = data[i];
        }
        newNode->next_ptr = q.head;

        q.head = newNode;
        if (q.tail == nullptr)
        {
            q.tail = newNode;
        }
        q.size++;
    }

    void create_queue(Queue& q, int n)
    {
        char value[100]; 
        cout << "Введите элемент 1: ";
        cin >> value;
        initQueue(q, value);
        for (int i = 2; i <= n; i++)
        {
            cout << "Введите элемент " << i << ": ";
            cin >> value;
            push(q, value);
        }
        return;
    }

    void deleteAfter(Queue& q, const char* Data)
    {
        if (q.head == nullptr)
        {
            cout << "Очередь пуста" << endl;
            return;
        }

        Node* node = q.head;
        while (node != nullptr)
        {
            if (strcmp(node->data, Data) == 0)
            {
                if (node->next_ptr != nullptr)
                {
                    Node* deleteElement = node->next_ptr;
                    node->next_ptr = deleteElement->next_ptr;
                    if (deleteElement == q.tail)
                    {
                        q.tail = node;
                    }
                    delete[] deleteElement->data;  
                    delete deleteElement;
                    q.size--;
                    return;
                }
                else
                {
                    cout << "После элемента " << Data << " нет других элементов" << endl;
                    return;
                }
            }
            node = node->next_ptr;
        }
        cout << "Элемент " << Data << " не найден в очереди" << endl;
    }

    void addKElements(Queue& q, int K) 
    {
        for (int i = 0; i < K; ++i)
        {
            char data[100]; 
            cout << "Введите значение для нового элемента (" << i + 1 << "/" << K << "): ";
            cin >> data;
            push_front(q, data);
        }
    }

    void Show(Queue& q) 
    {
        cout << "Начало -> ";
        Node* temp = q.head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next_ptr;
        }
        cout << "Конец" << endl;
        return;
    }

    void clearQueue(Queue& q) 
    {
        Node* temp = q.head;
        while (temp != nullptr)
        {
            Node* next = temp->next_ptr;
            delete[] temp->data;  
            delete temp;
            temp = next;
        }
        q.head = nullptr;
        q.tail = nullptr;
        q.size = 0;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
    Queue q;
    q.head = nullptr;
    q.tail = nullptr;
    q.size = 0;

    cout << "Введите количество элементов в очереди: ";
    int n;
    cin >> n;
    q.create_queue(q, n);
    cout << endl;
    cout << "Ваша очередь: ";
    q.Show(q);

    cout << "Введите значение элемента после которого удалится элемент: ";
    char b[100]; 
    cin >> b;
    q.deleteAfter(q, b);
    cout << "Ваша очередь после удаления элемента: ";
    q.Show(q);

    cout << "Введите количество элементов, которое вы хотите добавить в начало очереди: ";
    int k;
    cin >> k;
    q.addKElements(q, k);
    cout << "Ваша очередь после добавления элементов: ";
    q.Show(q);

    q.clearQueue(q);
    return 0;
}
