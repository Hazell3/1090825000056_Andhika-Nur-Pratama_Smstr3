#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};

    cout << "=== Array A (awal) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (awal) ===" << endl;
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan posisi yang ditukar (baris kolom, 0-2): ";
    cin >> baris >> kolom;
    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "Posisi tidak valid!" << endl;
        return 1;
    }
    tukarArray(A, B, baris, kolom);

    cout << "\n=== Array A (setelah tukar posisi [" << baris << "][" << kolom << "]) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (setelah tukar posisi [" << baris << "][" << kolom << "]) ===" << endl;
    tampilArray(B);

    int *ptr1 = &A[0][0];
    int *ptr2 = &B[2][2];

    cout << "\nSebelum tukar pointer : *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Sesudah tukar pointer : *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    cout << "\n=== Array A (akhir) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (akhir) ===" << endl;
    tampilArray(B);

    return 0;
}