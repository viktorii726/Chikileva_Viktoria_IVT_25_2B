#include <iostream>
#include<clocale>

using namespace std;

int main()
{   
    setlocale(LC_ALL, ("RUS"));
    const int n = 7;
    int tmp; 
    int arr[n] = { 5, 2, 4, 6, 0, 1, 3 };

    cout << "Исходный массив: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
  
        if (min_index != i)
        {
            tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }    

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

       
    }

   
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
