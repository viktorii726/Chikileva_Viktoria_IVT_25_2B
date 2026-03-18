#include <iostream>
#include <clocale>

using namespace std;

const int MAX_SIZE = 100;

void front(int& i, int n)
{
    if (i == n - 1)
    {
        i = 0;
    }
    else
    {
        i += 1;
    }
}

void printRing(int arr[], int n, int k)
{
    if (n == 0) {
        cout << "Кольцо пусто" << endl;
        return;
    }

    cout << "Кольцо: ";
    int idx = k - 1;
    for (int i = 0; i < n; i++) {
        cout << arr[idx] << " ";
        front(idx, n);
    }
    cout << endl;
}

int main() {

    setlocale(LC_ALL, "rus");

    int arr[MAX_SIZE], n, k;

    cout << "Введите размер массива: ";
    cin >> n;

    while (n <= 0 || n > MAX_SIZE) {
        cout << "Ошибка!";
        cin >> n;
    }

    cout << "Введите " << n << " элементов массива: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Введите K (1-" << n << "): ";
    cin >> k;

    while (k < 1 || k > n) {
        cout << "Ошибка! K должно быть от 1 до " << n << ": ";
        cin >> k;
    }

    cout << "Исходное кольцо: " << endl;
    printRing(arr, n, k);


    int first, last;
    cout << "Введите новый первый элемент: ";
    cin >> first;
    cout << "Введите новый последний элемент: ";
    cin >> last;


    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = first;
    n += 1;


    arr[n] = last;
    n += 1;

    cout << "После добавления:" << endl;
    printRing(arr, n, k);

    cout << "Удаление четных элементов:" << endl;
    int temp[MAX_SIZE];
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[cnt] = arr[i];
            cnt++;
        }
    }

    if (cnt == n) {
        cout << "Четных элементов не найдено" << endl;
    }
    else {
        cout << "Удалено " << n - cnt << " четных элементов" << endl;
    }

    n = cnt;
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    cout << "Итоговое кольцо: " << endl;


    cout << "После удаления четных элементов:" << endl;
    printRing(arr, n, k);

    return 0;
}