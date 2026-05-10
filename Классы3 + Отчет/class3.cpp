#include <iostream>
using namespace std;

class Pair {
    int first;
    double second;
public:
    Pair() : first(0), second(0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair(const Pair& other) : first(other.first), second(other.second) {}
    ~Pair() {}

    int getFirst() const { return first; }
    double getSecond() const { return second; }
    void setFirst(int f) { first = f; }
    void setSecond(double s) { second = s; }

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    friend bool operator<(const Pair& a, const Pair& b) {
        return a.first != b.first ? a.first < b.first : a.second < b.second;
    }

    friend bool operator>(const Pair& a, const Pair& b) {
        return a.first != b.first ? a.first > b.first : a.second > b.second;
    }

    Pair& operator--() { first--; return *this; }
    Pair operator--(int) { Pair temp = *this; second--; return temp; }

    friend ostream& operator<<(ostream& os, const Pair& p) {
        return os << p.first << ":" << p.second;
    }

    friend istream& operator>>(istream& is, Pair& p) {
        cout << "Введите первое число (int): ";
        is >> p.first;
        cout << "Введите второе число (double): ";
        is >> p.second;
        return is;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Pair p1, p2;

    cout << "Ввод данных для p1 " << endl;
    cin >> p1;

    cout << "\n Ввод данных для p2 " << endl;
    cin >> p2;

    cout << "\n Результаты " << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    Pair p3(p1);
    cout << "p3 (копия p1) = " << p3 << endl;

    p3 = p2;
    cout << "p3 после присваивания p2 = " << p3 << endl;

    cout << "\nСравнение p1 и p2:" << endl;
    cout << "p1 < p2: " << (p1 < p2 ? "true" : "false") << endl;
    cout << "p1 > p2: " << (p1 > p2 ? "true" : "false") << endl;

    cout << "\nДемонстрация оператора -- :" << endl;
    cout << "p1 до --p1: " << p1 << endl;
    --p1;
    cout << "p1 после --p1: " << p1 << endl;

    cout << "p2 до p2--: " << p2 << endl;
    p2--;
    cout << "p2 после p2--: " << p2 << endl;

    return 0;
}