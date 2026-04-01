#include <iostream>
#include <string>
#include<clocale>
using namespace std;


int f(int a[], int n) 
{
    if (n <= 0) return 0;

    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }
    return m;
}


int f(string s) {
    if (s.empty()) return 0;

    int max = 0;
    int cur = 0;

    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == ' ') {
            if (cur > max) {
                max = cur;
            }
            cur = 0;
        }
        else {
            cur++;
        }
    }

    return max;
}

int main() {
    setlocale(LC_ALL, "rus");

   
    cout << " Поиск максимума в массиве " << endl;

    int n;
    cout << "Размер: ";
    cin >> n;

    int* a = new int[n];

    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m1 = f(a, n);
    cout << "Максимум: " << m1 << endl;

    delete[] a;

    
    cout << " Длина самого длинного слова: " << endl;

    string s;
    cout << "Введите строку: ";

    cin.ignore();  
    getline(cin, s);

    int m2 = f(s);
    cout << "Длина: " << m2 << endl;

    return 0;
}