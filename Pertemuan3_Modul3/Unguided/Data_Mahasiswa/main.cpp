#include <iostream>
#include "dataMahasiswa.h"
using namespace std;

int main() {
    Mahasiswa dataMhs[10];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << "\n=== Data mahasiswa ke-" << i + 1 << " ===" << endl;
        inputMhs(dataMhs[i]);
    }

    cout << "\n===== DAFTAR MAHASISWA =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Mahasiswa ke-" << i + 1 << " ---" << endl;
        tampilMhs(dataMhs[i]);
    }
    return 0;
}