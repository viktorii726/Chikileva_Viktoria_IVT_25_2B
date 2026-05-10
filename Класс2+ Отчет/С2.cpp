#include <iostream>
#include <string>
#include <clocale>

using namespace std;

class Abityrient
{
private:
    string fio;
    string spetsial;
    int ball;

public:
    // Конструкторы
    Abityrient();                              // без параметров
    Abityrient(string, string, int);           // с параметрами
    Abityrient(const Abityrient&);             // копирования

    // Деструктор
    ~Abityrient();

    // Селекторы (геттеры)
    string get_fio();
    string get_spetsial();
    int get_ball();

    // Модификаторы (сеттеры)
    void set_fio(string);
    void set_spetsial(string);
    void set_ball(int);

    // Метод для вывода
    void show();
};

// Конструктор без параметров
Abityrient::Abityrient()
{
    fio = "";
    spetsial = "";
    ball = 0;
    cout << "Конструктор без параметров для объекта " << this << endl;
}

// Конструктор с параметрами
Abityrient::Abityrient(string N, string F, int S)
{
    fio = N;
    spetsial = F;
    ball = S;
    cout << "Конструктор с параметрами для объекта " << this << endl;
}

// Конструктор копирования
Abityrient::Abityrient(const Abityrient& t)
{
    fio = t.fio;
    spetsial = t.spetsial;
    ball = t.ball;
    cout << "Конструктор копирования для объекта " << this << endl;
}

// Деструктор
Abityrient::~Abityrient()
{
    cout << "Деструктор для объекта " << this << endl;
}

// Селекторы (геттеры)
string Abityrient::get_fio()
{
    return fio;
}

string Abityrient::get_spetsial()
{
    return spetsial;
}

int Abityrient::get_ball()
{
    return ball;
}

// Модификаторы (сеттеры)
void Abityrient::set_fio(string N)
{
    fio = N;
}

void Abityrient::set_spetsial(string F)
{
    spetsial = F;
}

void Abityrient::set_ball(int S)
{
    ball = S;
}

// Метод для вывода информации
void Abityrient::show()
{
    cout << "ФИО: " << fio << endl;
    cout << "Специальность: " << spetsial << endl;
    cout << "Балл ЕГЭ: " << ball << endl;
}

// Функция для создания объекта (демонстрация возврата объекта)
Abityrient make_abi()
{
    string s, d;
    int i;

    cout << "\n--- Создание нового абитуриента ---\n";
    cout << "ФИО: ";
    cin.ignore();  // Очищаем буфер
    getline(cin, s);  // Используем getline для чтения строки с пробелами
    cout << "Специальность: ";
    getline(cin, d);
    cout << "Балл ЕГЭ: ";
    cin >> i;

    Abityrient t(s, d, i);
    return t;  // Здесь вызывается конструктор копирования
}

// Функция для передачи объекта по значению (демонстрация конструктора копирования)
void print_abi(Abityrient t)
{
    cout << "\n--- Вывод объекта внутри функции ---\n";
    t.show();  // Здесь объект t - копия переданного объекта
}

int main()
{
    setlocale(LC_ALL, "ru");

    // 1. Конструктор без параметров
    cout << "1. СОЗДАНИЕ ОБЪЕКТА БЕЗ ПАРАМЕТРОВ:\n";
    Abityrient t1;
    cout << "\nСодержимое объекта t1:\n";
    t1.show();
   

    // 2. Конструктор с параметрами
    cout << "2. СОЗДАНИЕ ОБЪЕКТА С ПАРАМЕТРАМИ:\n";
    Abityrient t2("Кисляк Андрей Викторович", "Математика", 99);
    cout << "\nСодержимое объекта t2:\n";
    t2.show();
    

    // 3. Конструктор копирования (инициализация)
    cout << "3. КОНСТРУКТОР КОПИРОВАНИЯ (t3 = t2):\n";
    Abityrient t3 = t2;  // Вызов конструктора копирования
    cout << "\nСодержимое объекта t3 (копия t2):\n";
    t3.show();

    // Изменяем t3 через модификаторы
    cout << "\nИзменяем данные в t3:\n";
    t3.set_fio("Понамарев Михаил Иванович");
    t3.set_spetsial("Биология");
    t3.set_ball(67);
    cout << "\nСодержимое объекта t3 после изменения:\n";
    t3.show();
    cout << "\nСодержимое объекта t2 (не изменилось):\n";
    t2.show();
   

    // 4. Конструктор копирования (передача в функцию)
    cout << "4. КОНСТРУКТОР КОПИРОВАНИЯ (передача в функцию):\n";
    print_abi(t3);
   

    // 5. Конструктор копирования (возврат из функции)
    cout << "5. КОНСТРУКТОР КОПИРОВАНИЯ (возврат из функции):\n";
    t1 = make_abi();  // make_abi() возвращает объект (копирование)
    cout << "\nСодержимое объекта t1 после присваивания:\n";
    t1.show();
   

    // Демонстрация работы селекторов
    cout << "6. ДЕМОНСТРАЦИЯ РАБОТЫ СЕЛЕКТОРОВ (геттеров):\n";
    cout << "ФИО из t2: " << t2.get_fio() << endl;
    cout << "Специальность из t2: " << t2.get_spetsial() << endl;
    cout << "Балл ЕГЭ из t2: " << t2.get_ball() << endl;
   

    return 0;
}