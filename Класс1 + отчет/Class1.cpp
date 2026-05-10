#include <iostream>
#include<clocale>
using namespace std;

class Number {
private:
    int first;      // целая часть
    double second;  // дробная часть

public:
    // Метод инициализации
    void Init(int f, double s) {
        if (f < 0 || s < 0 || s >= 1) {
            cout << "Ошибка! Целая часть >= 0, дробная от 0 до 1" << endl;
            return;
        }
        first = f;
        second = s;
    }

    // Метод ввода
    void Read() {
        int f;
        double s;
        cout << "Введите целую часть: ";
        cin >> f;
        cout << "Введите дробную часть: ";
        cin >> s;
        Init(f, s);
    }

    // Метод вывода
    void Show() {
        cout << "Число: " << first + second << endl;
        cout << "Целая часть: " << first << ", Дробная: " << second << endl;
    }

    // Метод умножения
    void multiply(double k) {
        double result = (first + second) * k;
        first = (int)result;           // целая часть
        second = result - first;        // дробная часть
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    // Создание объекта
    Number num;

    // Ввод числа
    cout << "Введите число:" << endl;
    num.Read();

    // Вывод числа
    cout << "\nИсходное число:" << endl;
    num.Show();

    // Умножение
    double k;
    cout << "\nВведите множитель: ";
    cin >> k;
    num.multiply(k);

    // Вывод результата
    cout << "\nРезультат умножения:" << endl;
    num.Show();

    return 0;
}