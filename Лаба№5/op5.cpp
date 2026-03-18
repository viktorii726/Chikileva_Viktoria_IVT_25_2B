#include <iostream>
using namespace std;

const int SZ = 100;

void printMatr(int a[SZ][SZ], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void swapRows(int a[SZ][SZ], int n, int r1, int r2) {
    if (r1 == r2) return;
    for (int j = 0; j < n; j++) {
        int temp = a[r1][j];
        a[r1][j] = a[r2][j];
        a[r2][j] = temp;
    }
}

void swapCols(int a[SZ][SZ], int n, int c1, int c2) {
    if (c1 == c2) return;
    for (int i = 0; i < n; i++) {
        int temp = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = temp;
    }
}

void findMax(int a[SZ][SZ], int n, int r, int c, int& mr, int& mc, int& mv) {
    int size = r + 1;
    if (n - c < size) {
        size = n - c;
    }

    int top = r - size + 1;
    int left = c;

    mv = a[top][left];
    mr = top;
    mc = left;

    for (int i = top; i <= r; i++) {
        for (int j = left; j <= c + size - 1; j++) {
            if (a[i][j] > mv) {
                mv = a[i][j];
                mr = i;
                mc = j;
            }
        }
    }
}

void processMatr(int a[SZ][SZ], int n) {
    for (int i = 0; i < n; i++) {
        int tr = i;
        int tc = n - 1 - i;

        int mr, mc, mv;
        findMax(a, n, tr, tc, mr, mc, mv);

        int size = tr + 1;
        if (n - tc < size)
            size = n - tc;

        int topRow = tr - size + 1;
        int rightCol = tc + size - 1;

        if (mr != topRow) {
            swapRows(a, n, mr, topRow);
            mr = topRow;
        }

        if (mc != rightCol) {
            swapCols(a, n, mc, rightCol);
        }
    }
}

bool checkDiag(int a[SZ][SZ], int n) {
    for (int i = 0; i < n - 1; i++)
        if (a[i][n - 1 - i] <= a[i + 1][n - 2 - i])
            return false;
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n, a[SZ][SZ];

    cout << "Введите размер матрицы N (до " << SZ << "): ";
    cin >> n;

    if (n > SZ || n <= 0) {
        cout << "Некорректный размер." << endl;
        return 1;
    }

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "\nИсходная матрица:" << endl;
    printMatr(a, n);

    processMatr(a, n);

    cout << "Итоговая матрица:" << endl;
    printMatr(a, n);

    cout << "Побочная диагональ: ";
    for (int i = 0; i < n; i++) {
        cout << a[i][n - 1 - i] << " ";
    }
    cout << endl;

    if (checkDiag(a, n))
        cout << " убывающая последовательность." << endl;
    else
         cout << " убывающая последовательность." << endl;
    return 0;
}