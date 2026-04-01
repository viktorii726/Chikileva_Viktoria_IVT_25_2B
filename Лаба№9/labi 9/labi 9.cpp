#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool pov(string stroka) 
{
    string slova[100];  
    int countSlov = 0;
    string word = "";

   
    for (int i = 0; i <= stroka.length(); i++) 
    {
        
        if (stroka[i] == ' ' || i == stroka.length()) 
        {
            if (word != "") 
            {
                for (int j = 0; j < countSlov; j++) 
                {
                    if (slova[j] == word) 
                    {
                        return true;  
                    }
                }
                
                slova[countSlov] = word;
                countSlov++;
                word = "";
            }
        }
        else 
        {
            word += stroka[i];  
        }
    }
    return false;  
}


int countGl(string stroka) 
{
    char glasnye[] = { 'а', 'е', 'ё', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я',
                      'А', 'Е', 'Ё', 'И', 'О', 'У', 'Ы', 'Э', 'Ю', 'Я',
                      'a', 'e', 'i', 'o', 'u', 'y',
                      'A', 'E', 'I', 'O', 'U', 'Y' };
    int count = 0;

    
    for (int i = 0; i < stroka.length(); i++) 
    {
        for (int j = 0; j < 32; j++) 
        { 
            if (stroka[i] == glasnye[j]) 
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() 
{
    setlocale(LC_ALL, "Russian");  

    ifstream f1("F1.txt");
    ofstream f2("F2.txt");

    if (!f1.is_open() || !f2.is_open()) 
    {
        cout << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    cout << "Копируем строки без повторяющихся слов из F1 в F2" << endl;

   
    string line;
    int copiedLines = 0;

    while (getline(f1, line)) 
    {
        if (!pov(line)) 
        {
            f2 << line << endl;
            cout << "Скопировано: " << line << endl;
            copiedLines++;
            
        }
    }

    cout << "Скопировано строк: " << copiedLines << endl;

 
    f1.close();
    f2.close();

    
    ifstream f2Read("F2.txt");

    if (!f2Read.is_open()) 
    {
        cout << "Ошибка открытия F2.txt для чтения!" << endl;
        return 1;
    }

    string firstLine;
    getline(f2Read, firstLine);
    f2Read.close();

    if (firstLine == "") 
    {
        cout << "Файл F2 пуст!" << endl;
        return 1;
    }

  
    int vowels = countGl(firstLine);

    cout << "\nПервая строка файла F2: " << firstLine << endl;
    cout << "Количество гласных букв: " << vowels << endl;

    return 0;
}