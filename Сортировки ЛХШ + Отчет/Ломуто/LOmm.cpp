#include <iostream>
#include<clocale>

using namespace std;

// Функция для вывода массива с указанием текущих элементов
void printArray(int arr[], int n, int pivotIdx = -1, int currIdx = -1, int swapIdx = -1) {
    for (int i = 0; i < n; i++) {
        if (i == pivotIdx) {
            cout << "[" << arr[i] << "] ";  // pivot в скобках
        }
        else if (i == currIdx) {
            cout << "(" << arr[i] << ") ";  // текущий элемент в скобках
        }
        else if (i == swapIdx) {
            cout << "{" << arr[i] << "} ";  // обмениваемый элемент в фигурных
        }
        else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Функция partition Lomuto для сортировки по возрастанию
int partitionLomuto(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    cout << "  Pivot = " << pivot << endl;
    printArray(arr, n, high);

    for (int j = low; j < high; j++) {
        cout << "    Сравниваем " << arr[j] << " с " << pivot << ": ";

        if (arr[j] < pivot) {  // МЕНЯЕМ > на < для сортировки по возрастанию
            i++;
            cout << arr[j] << " < " << pivot << " -> меняем ";
            swap(arr[i], arr[j]);
            cout << arr[i] << " и " << arr[j] << endl;
            printArray(arr, n, high, j, i);
        }
        else {
            cout << arr[j] << " >= " << pivot << " -> ничего не делаем" << endl;
            printArray(arr, n, high, j);
        }
    }

    cout << "  Ставим pivot на место: меняем " << arr[i + 1] << " и " << arr[high] << endl;
    swap(arr[i + 1], arr[high]);
    printArray(arr, n, i + 1);

    return i + 1;
}

// Быстрая сортировка
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partitionLomuto(arr, low, high, n);

        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int arr[] = { 3, 8, 10, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    quickSort(arr, 0, n - 1, n);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}