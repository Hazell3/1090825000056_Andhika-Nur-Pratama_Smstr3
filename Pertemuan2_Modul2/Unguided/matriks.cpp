#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {27, 56, 30},
        {55, 21, 29},
        {75, 90, 42}
    };

    int nilai2[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int hasil[3][3];

    cout << "Hasil Penjumlahan:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = nilai[i][j] + nilai2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = nilai[i][j] - nilai2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] = hasil[i][j] + nilai[i][k] * nilai2[k][j];
            }
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}