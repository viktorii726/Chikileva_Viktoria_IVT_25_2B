#include <iostream>
#include <fstream>
#include <cstring>
#include<clocale>


using namespace std;

struct Book {
    char title[50];
    char author[50];
    int year;
    int pages;
};

void add_book(Book b[], int& n) {
    cout << "Название: ";
    cin >> b[n].title;
    cout << "Автор: ";
    cin >> b[n].author;
    cout << "Год: ";
    cin >> b[n].year;
    cout << "Страницы: ";
    cin >> b[n].pages;
    n++;
}

void print(Book b[], int n) {
    if (n == 0) {
        cout << "Список пуст\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << b[i].title << " "
            << b[i].author << " "
            << b[i].year << " "
            << b[i].pages << endl;
    }
}

void delete_first_three(Book b[], int& n) {
    if (n <= 3) {
        n = 0;
        return;
    }

    for (int i = 3; i < n; i++) {
        b[i - 3] = b[i];
    }

    n -= 3;
}

void add_before(Book b[], int& n) {

    char name[50];
    cout << "Перед какой книгой добавить: ";
    cin >> name;

    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(b[i].title, name) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Книга не найдена\n";
        return;
    }

    for (int i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }

    cout << "Введите новую книгу\n";
    cout << "Название: ";
    cin >> b[pos].title;
    cout << "Автор: ";
    cin >> b[pos].author;
    cout << "Год: ";
    cin >> b[pos].year;
    cout << "Страницы: ";
    cin >> b[pos].pages;

    n++;
}

int save(Book b[], int n) {

    ofstream f("books.dat", ios::binary);

    if (!f)
        return 1;

    for (int i = 0; i < n; i++) {
        f.write((char*)&b[i], sizeof(Book));
    }

    f.close();
    return 0;
}

int load(Book b[], int& n) {

    ifstream f("books.dat", ios::binary);

    if (!f)
        return 1;

    n = 0;

    while (f.read((char*)&b[n], sizeof(Book))) {
        n++;
    }

    f.close();
    return 0;
}

int main() {
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");

    Book Books[100];
    int cnt = 0;
    char z = '1';

    while (z != '0') {

        cout << "\n1 - Добавить книгу\n";
        cout << "2 - Удалить 3 первые\n";
        cout << "3 - Добавить перед книгой\n";
        cout << "4 - Сохранить в файл\n";
        cout << "5 - Показать\n";
        cout << "6 - Загрузить из файла\n";
        cout << "0 - Выход\n";

        cin >> z;

        if (z == '1') {
            add_book(Books, cnt);
        }
        else if (z == '2') {
            delete_first_three(Books, cnt);
        }
        else if (z == '3') {
            add_before(Books, cnt);
        }
        else if (z == '4') {
            if (save(Books, cnt) == 1) {
                cout << "Ошибка записи\n";
            }
        }
        else if (z == '5') {
            print(Books, cnt);
        }
        else if (z == '6') {
            if (load(Books, cnt) == 1) {
                cout << "Ошибка чтения файла\n";
            }
        }
        else if (z == '0') {
            break;
        }
        else {
            cout << "Ошибка ввода команды\n";
        }
    }

    return 0;
}