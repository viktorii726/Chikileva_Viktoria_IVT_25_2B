#include <iostream>
#include <clocale>
using namespace std;

const int size_arr = 8;
int arr[size_arr][size_arr];
int attempt = 1;

void show() {
    for (int i = 0; i < size_arr; i++) {
        for (int j = 0; j < size_arr; j++) {
            cout << (arr[i][j] ? "F " : "# ");
        }
        cout << endl;
    }
    cout << endl;
}
bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (arr[i][col]) {
            return false;
        }
    }
    for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
        if (arr[row - i][col - i]) {
            return false;
        }
    }
    for (int i = 1; row - i >= 0 && col + i < size_arr; i++) {
        if (arr[row - i][col + i]) {
            return false;
        }
    }
    return true;
}
void game(int row, int n) {
    setlocale(LC_ALL, "ru");
    if (row == size_arr) {
        cout << "Правильная расстановка " << endl << endl;
        show();
        attempt++;
        return;
    }
    for (int col = n; col < size_arr && attempt < 2; col++) {
        if (check(row, col)) {
            arr[row][col] = 1;
            show();
            game(row + 1, 0);
            if (attempt < 2) {
                arr[row][col] = 0;
                show();
            }
        }
    }
}
int main() {
    int n = 1;
    game(0, n - 1);
    return 0;
}
