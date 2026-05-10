#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int m, n, ss1[100][100], ss2[100][100];

    cout << "Введите кол-во строк:";
    cin >> n;
    cout << "Введите кол-во столбцов:";
    cin >> m;
    cout << "Введите элементы массива через пробел:";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ss1[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ss2[j][i] = ss1[i][j];
        }
    }

    cout << "Транспонированный массив:" << endl;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            ss1[i - 1][j - 1] = ss2[i - 1][j - 1];
            cout << ss1[i - 1][j - 1] << " ";
        }
        cout << endl;
    }

}

