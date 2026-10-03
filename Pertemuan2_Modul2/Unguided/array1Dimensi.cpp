#include <iostream>
using namespace std;

int cariMinimum(int arrA[]) {
    int min = arrA[0];
    for (int i = 1; i < 10; i++) {
        if (arrA[i] < min) {
            min = arrA[i];
        }
    }
    return min;
}

int cariMaksimum(int arrA[]) {
    int max = arrA[0];
    for (int i = 1; i < 10; i++) {
        if (arrA[i] > max) {
            max = arrA[i];
        }
    }
    return max;
}

void hitungRataRata(int arrA[]) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        total = total + arrA[i];
    }
    cout << "Nilai rata-rata = " << total / 10.0 << endl;
}

int main() {
    int arrA[10];

    arrA[0] = 11;
    arrA[1] = 8;
    arrA[2] = 5;
    arrA[3] = 7;
    arrA[4] = 12;
    arrA[5] = 26;
    arrA[6] = 3;
    arrA[7] = 54;
    arrA[8] = 33;
    arrA[9] = 55;

    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    cout << "Data ke-" << i + 1 << " = "
                    << arrA[i] << endl;
                }
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA) << endl;
                break;
            case 4:
                hitungRataRata(arrA);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}