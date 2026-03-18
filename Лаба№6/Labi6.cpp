#include <iostream>
#include <cstring>
#include <clocale>

using namespace std;

int main() 
{

    setlocale(LC_ALL, "Russian");

    char text[256];
    cout << "Введите текст (в конце поставьте точку): " << endl;
    cin.getline(text, 256);

    char words[128][128];
    int n = 0; 
    char word[128] = "";
    int p = 0; 

    int len = strlen(text);

    for (int i = 0; i < len; i++) 
    {
        char c = text[i];

        if (c != ' ' && c != '.') 
        {
            word[p] = c;
            p++;
        }
        else 
        {
            if (p > 0) 
            {
                word[p] = '\0';
                char first = word[0];
                bool is_letter = (first >= 'a' && first <= 'z') || 
                    (first >= 'A' && first <= 'Z') || 
                    (first >= 'а' && first <= 'я') || 
                    (first >= 'А' && first <= 'Я');
                if (is_letter) 
                {
                    strcpy(words[n], word);
                    n++;
                }

                p = 0;
                word[0] = '\0';
            }

            if (c == '.') 
                break;
        }
    }

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (strcmp(words[j], words[j + 1]) > 0) 
            {
                char temp[128];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    cout << "Слова, начинающиеся с буквы, в алфавитном порядке:" << endl;
    if (n == 0) 
    {
        cout << "Таких слов не найдено." << endl;
    }
    else 
    {
        for (int i = 0; i < n; i++) 
        {
            cout << words[i] << " ";
        }
        cout << endl;
    }

    
}