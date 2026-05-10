#include <iostream>
#include<clocale>

using namespace std;

// Функция для вывода массива с указанием текущих элементов
void printArray(int arr[], int n, int pivotIdx = -1, int leftIdx = -1, int rightIdx = -1) {
    for (int i = 0; i < n; i++) {
        if (i == pivotIdx) {
            cout << "[" << arr[i] << "] ";  // pivot в квадратных скобках
        }
        else if (i == leftIdx) {
            cout << "(" << arr[i] << ") ";  // левый указатель
        }
        else if (i == rightIdx) {
            cout << "{" << arr[i] << "} ";  // правый указатель
        }
        else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Разбиение Хоара
int partitionHoare(int arr[], int low, int high, int n) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    cout << "  Pivot = " << pivot << " (индекс " << (low + (high - low) / 2) << ")" << endl;
    printArray(arr, n, low + (high - low) / 2);

    while (true) {
        // ищем элемент слева, который больше или равен pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // ищем элемент справа, который меньше или равен pivot
        do {
            j--;
        } while (arr[j] > pivot);

        cout << "    i = " << i << " (значение " << arr[i] << "), j = " << j << " (значение " << arr[j] << ")" << endl;
        printArray(arr, n, -1, i, j);

        // если индекс пересеклись, возвращаем индекс разделения
        if (i >= j) {
            cout << "    Индексы пересеклись (i >= j), возвращаем j = " << j << endl;
            return j;
        }

        cout << "    Меняем местами " << arr[i] << " и " << arr[j] << endl;
        swap(arr[i], arr[j]);
        printArray(arr, n, -1, i, j);
    }
}

// Быстрая сортировка Хоара
void quickSortHoare(int arr[], int low, int high, int n) {
    if (low < high) {
        cout << "\n--- Сортируем отрезок [" << low << ".." << high << "] ---" << endl;
        int pi = partitionHoare(arr, low, high, n);

        cout << "\n  Левая часть: [" << low << ".." << pi << "]" << endl;
        quickSortHoare(arr, low, pi, n);

        cout << "\n  Правая часть: [" << pi + 1 << ".." << high << "]" << endl;
        quickSortHoare(arr, pi + 1, high, n);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int arr[] = { 3, 6, 8, 10, };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\nНачинаем сортировку Хоара (по возрастанию):\n";
    quickSortHoare(arr, 0, n - 1, n);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}