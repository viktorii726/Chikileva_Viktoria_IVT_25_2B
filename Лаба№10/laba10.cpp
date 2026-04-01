#include <iostream>
#include <string>
#include<clocale>
using namespace std;

int main() {
    
    setlocale(LC_ALL, "Rus");
    int size;
    cout << "Введите количество строк: " << endl;
    cin >> size;

    
    string* arr = new string[size];

   
    cout << "Введите " << size << " строк:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Строка " << i + 1 << ": ";
        cin >> arr[i];
    }

    
    int newSize = 0;

    
    for (int i = 0; i < size; i++) {
        if (arr[i][0] != 'a') {
            newSize++;
        }
    }

   
    string* resultArr = new string[newSize];

    
    int resultIndex = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i][0] != 'a') {
            resultArr[resultIndex] = arr[i];
            resultIndex++;
        }
    }

    
    cout << "Строки, не начинающиеся на 'а':" << endl;
    if (newSize > 0) {
        for (int i = 0; i < newSize; i++) {
            cout << i + 1 << ": " << resultArr[i] << endl;
        }
    }
    else {
        cout << "Массив пуст" << endl;
    }

    cout << "Удалено строк: " << size - newSize << endl;

    
    delete[] arr;
    delete[] resultArr;

    return 0;
}