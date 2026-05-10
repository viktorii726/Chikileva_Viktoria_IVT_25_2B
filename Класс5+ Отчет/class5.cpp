#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() {
        name = "Неизвестно";
        age = 0;
    }

    Person(string n, int a) {
        name = n;
        age = a;
    }

    virtual ~Person() {}

    string getName() { return name; }
    int getAge() { return age; }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }

    virtual void show() = 0;
    virtual double getSalary() = 0;
};

class Employee : public Person {
private:
    string position;
    double salary;

public:
  
    Employee() : Person() {
        position = "Не указана";
        salary = 0;
    }

    Employee(string n, int a, string pos, double sal) : Person(n, a) {
        position = pos;
        salary = sal;
    }

    void show() {
        cout << "Сотрудник: " << name << ", " << age << " лет, "
            << position << ", оклад: " << salary << endl;
    }

    double getSalary() {
        return salary;
    }

    void setPosition(string pos) { position = pos; }
    string getPosition() { return position; }
};

class Student : public Person {
private:
    double scholarship;  

public:
    Student() : Person() {
        scholarship = 0;
    }

    Student(string n, int a, double stip) : Person(n, a) {
        scholarship = stip;
    }

    void show() {
        cout << "Студент: " << name << ", " << age << " лет, "
            << "стипендия: " << scholarship << endl;
    }

    double getSalary() {
        return scholarship;
    }

    void setScholarship(double stip) { scholarship = stip; }
    double getScholarship() { return scholarship; }
};

class Vector {
private:
    Person** arr;   // Указатель на массив указателей
    int size;       
    int capacity;   

public:
    Vector() {
        size = 0;
        capacity = 10;
        arr = new Person * [capacity];
    }

    ~Vector() {
        for (int i = 0; i < size; i++) {
            delete arr[i];  
        }
        delete[] arr;       
    }

    void add(Person* p) {
        if (size == capacity) {
            capacity *= 2;
            Person** newArr = new Person * [capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size] = p;
        size++;
    }

    Person* get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return nullptr;
    }

    int getSize() {
        return size;
    }

    friend ostream& operator<<(ostream& out, Vector& v) {
        out << "\n Содержимое вектора (" << v.size << " элементов) " << endl;
        for (int i = 0; i < v.size; i++) {
            out << i + 1 << ". ";
            v.arr[i]->show();  // ПОЛИМОРФИЗМ!
        }
        return out;
    }

    double totalIncome() {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i]->getSalary();  // ПОЛИМОРФИЗМ
        }
        return sum;
    }
};

int main() {
    setlocale(0, "");

    Vector people;

    people.add(new Employee("Иванов Иван", 30, "Программист", 50000));
    people.add(new Student("Петрова Анна", 20, 2000));
    people.add(new Employee("Сидоров Петр", 35, "Менеджер", 60000));
    people.add(new Student("Кузнецова Мария", 19, 2500));
    people.add(new Employee("Смирнов Алексей", 28, "Аналитик", 55000));

    cout << people;

    cout << "\n Общий доход всех людей " << endl;
    cout << "Всего: " << people.totalIncome() << " руб." << endl;

    cout << "\n Демонстрация полиморфизма (каждый объект сам знает, как выводиться) " << endl;
    for (int i = 0; i < people.getSize(); i++) {
        cout << "Элемент " << i + 1 << ": ";
        people.get(i)->show();  // Вызывается нужная версия функции
    }

    return 0;
}