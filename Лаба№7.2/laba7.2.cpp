#include <iostream>
#include <cstdarg>  
#include<clocale>

using namespace std;

int nod(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int nok(int a, int b) 
{
    
    return (a / nod(a, b)) * b;
}


int nok(int count, ...) 
{
    va_list args;
    va_start(args, count);

    
    int result = va_arg(args, int);

    
    for (int i = 1; i < count; i++) 
    {
        int next = va_arg(args, int);
        result = nok(result, next);
    }

    va_end(args);
    return result;
}

int main() {
    
    setlocale(LC_ALL, "Russian");

    int result1 = nok(3, 6, 8, 12);
    cout << "НОК(6, 8, 12) = " << result1 << endl;

   
    int result2 = nok(5, 2, 3, 4, 5, 6);
    cout << "НОК(2, 3, 4, 5, 6) = " << result2 << endl;

  
    int result3 = nok(6, 4, 6, 8, 10, 12, 15);
    cout << "НОК(4, 6, 8, 10, 12, 15) = " << result3 << endl;

    
    int result4 = nok(4, 7, 14, 21, 28);
    cout << "НОК(7, 14, 21, 28) = " << result4 << endl;

    return 0;
}