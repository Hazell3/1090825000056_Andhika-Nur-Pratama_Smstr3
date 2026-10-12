#include <iostream>
#include "dataMahasiswa.h"

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return uts * 0.3 + uas * 0.4 + tugas * 0.3;
}

void inputMhs(Mahasiswa &m) {
    cout << "Nama:          ";
    getline (cin >> ws, m.nama);
    cout << "NIM:           ";
    cin >> m.nim;
    cout << "UTS:           ";
    cin >> m.uts;
    cout << "UAS:           ";
    cin >> m.uas;
    cout << "Tugas:         ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m.uts, m.uas, m.tugas);
}

void tampilMhs(Mahasiswa &m) {
    cout << "Nama:          " << m.nama << endl;
    cout << "NIM:           " << m.nim << endl;
    cout << "UTS:           " << m.uts << endl;
    cout << "UAS:           " << m.uas << endl;
    cout << "Tugas:         " << m.tugas << endl;
    cout << "Nilai Akhir:   " << m.nilaiAkhir << endl;
}
