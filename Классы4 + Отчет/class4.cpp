#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() {
        name = " ";
        age = 0;
    }

    Person(string n, int a) {
        name = n;
        age = a;
    }

    Person(const Person& p) {
        name = p.name;
        age = p.age;
    }

    ~Person() {}

    string getName() { return name; }
    int getAge() { return age; }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }

    Person& operator=(const Person& p) {
        if (this != &p) {
            name = p.name;
            age = p.age;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Person& p) {
        cout << "Введите имя: "; in >> p.name;
        cout << "Введите возраст: "; in >> p.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, Person& p) {
        out << p.name << " (" << p.age << " лет)";
        return out;
    }

    virtual void show() {
        cout << "Человек: " << name << ", " << age << " лет" << endl;
    }
};

class Employee : public Person {
private:
    string position;
    double salary;
    double bonus;

public:
   
    Employee() : Person() {
        position = " ";
        salary = 0;
        bonus = 0;
    }

    Employee(string n, int a, string pos, double sal, double b) : Person(n, a) {
        position = pos;
        salary = sal;
        bonus = b;
    }

    Employee(const Employee& e) : Person(e) {
        position = e.position;
        salary = e.salary;
        bonus = e.bonus;
    }

    ~Employee() {}

    string getPosition() { return position; }
    double getSalary() { return salary; }
    double getBonus() { return bonus; }

    void setPosition(string pos) { position = pos; }
    void setSalary(double sal) { salary = sal; }
    void setBonus(double b) { bonus = b; }

    double calculateSalary() {
        return salary + salary * bonus / 100;
    }

    Employee& operator=(const Employee& e) {
        if (this != &e) {
            Person::operator=(e);
            position = e.position;
            salary = e.salary;
            bonus = e.bonus;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Employee& e) {
        in >> (Person&)e;
        cout << "Введите должность: "; in >> e.position;
        cout << "Введите оклад: "; in >> e.salary;
        cout << "Введите процент премии: "; in >> e.bonus;
        return in;
    }

    friend ostream& operator<<(ostream& out, Employee& e) {
        out << (Person&)e;
        out << ", " << e.position
            << ", оклад: " << e.salary
            << ", премия: " << e.bonus << "%";
        out << " (ИТОГО: " << e.calculateSalary() << ")";
        return out;
    }

    void show() {
        cout << "Сотрудник: " << getName() << ", " << getAge() << " лет, "
            << position << ", зарплата: " << calculateSalary() << endl;
    }
};

void funcTakePerson(Person p) {
    cout << "Функция получила: " << p << endl;
}

Person funcReturnPerson() {
    Person p("Созданный в функции", 99);
    return p;
}

int main() {
    setlocale(0, "");

    Person p1;
    Person p2("Иванов", 25);
    Person p3(p2);

    Employee e1;
    Employee e2("Петров", 30, "программист", 50000, 15);
    Employee e3(e2);

    cout << "p2: " << p2 << endl;
    cout << "e2: " << e2 << endl;

    p1.setName("Сидорова");
    p1.setAge(22);
    cout << "p1: " << p1 << endl;
    cout << "Имя e2: " << e2.getName() << endl;
    e2.setSalary(60000);
    cout << "Новая зарплата e2: " << e2.calculateSalary() << endl;

    Person p4;
    p4 = p2;
    cout << "p4 = p2: " << p4 << endl;

    Person p5;
    cout << "\nВвод для Person:" << endl;
    cin >> p5;
    cout << "Вы ввели: " << p5 << endl;

    Employee e4;
    cout << "\nВвод для Employee:" << endl;
    cin >> e4;
    cout << "Вы ввели: " << e4 << endl;

    funcTakePerson(p2);
    Person p6 = funcReturnPerson();
    cout << "Возвращено из функции: " << p6 << endl;

    cout << "\n--- Принцип подстановки ---" << endl;
    Person* ptr1 = &p2;
    Person* ptr2 = &e2;

    ptr1->show();  // вызов Person::show()
    ptr2->show();  // вызов Employee::show()

    cout << "\nГотово!" << endl;
    return 0;
}